`define TAG 15:10		// position of tag in address
`define INDEX 9:2	    // position of index in address
`define OFFSET 1:0		// position of offset in address

// 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
// |---------------|----------------------|-----|
// |TAG            |INDEX                 |OFF  |

module icache (input wire clk,
               input wire rst,
               input wire [15:0] address,       // address form CPU
               input wire [31:0] data_in_cpu,   // data from CPU (for store instruction)
               input wire [31:0] data_in_mem,   // data from memory (for store instruction)
               input wire rd,                   // read instruction, 1 for lpad instruction
               input wire wr,                   // write instruction, 1 for store instruction
               output wire data_ready,
               output wire hit_miss,            // 1 for hit, 0 while handling miss
               output wire [31:0] data2cpu,     // data from cache to CPU
               output wire [31:0] data2mem,     // data from cache to memory
               output wire [15:0] m_rd_address, // memory read address
               output wire [15:0] m_wr_address, // memory write address
               output wire mrden,               // read enable, 1 for reading from memory
               output wire mwren);              // write enable, 1 for writing to memory
    
    // WAY 1 cache data
    reg					valid1 [0:255];
    reg					dirty1 [0:255];
    reg					lru1   [0:255];
    reg [5:0]	        tag1   [0:255];
    reg [31:0]	        mem1   [0:255];
    
    // WAY 2 cache data
    reg					valid2 [0:255];
    reg					dirty2 [0:255];
    reg					lru2   [0:255];
    reg [5:0]           tag2   [0:255];
    reg [31:0]          mem2   [0:255];
    
    parameter IDLE = 0;
    parameter MISS = 1;
    parameter DONE = 2;
    integer i;
    
    reg [1:0] cs, ns;
    reg [31:0] _data2cpu;
    reg [31:0] _data2mem;
    reg [31:0] _m_wr_address;
    reg [3:0]  counter;
    reg _mwren;
    
    assign mrden        = rd && !((valid1[address[`INDEX]] && (tag1[address[`INDEX]] == address[`TAG])) || (valid2[address[`INDEX]] && (tag2[address[`INDEX]] == address[`TAG])));
    assign mwren        = _mwren;
    assign data2mem     = _data2mem;
    assign m_rd_address = address;
    assign m_wr_address = _m_wr_address;
    assign data2cpu     = _data2cpu;
    assign data_ready   = (cs == DONE);
    
    always @(posedge clk or posedge rst)
    begin
        if (rst)
        begin
            cs <= IDLE;
        end
        else
        begin
            cs <= ns;
        end
    end
    
    assign hit_miss = (cs == IDLE) && ((valid1[address[`INDEX]] && (tag1[address[`INDEX]] == address[`TAG])) || (valid2[address[`INDEX]] && (tag2[address[`INDEX]] == address[`TAG])));
    
    always @(cs or rd or wr or hit_miss or counter)
    begin
        case(cs)
            IDLE:   ns  = ((rd || wr) && !hit_miss)? MISS : ((rd || wr) && hit_miss)? DONE : IDLE;
            // MISS: ns = (wr)? DONE : ((counter == 7)? DONE : MISS);
            MISS:   ns  = DONE;
            DONE:   ns  = IDLE;
            default:ns  = IDLE;
        endcase
    end
    
    always @(posedge clk or posedge rst)
    begin
        if (rst)
        begin
            for(i = 0; i < 256; i = i + 1)
            begin
                valid1[i] <= 0;
                valid2[i] <= 0;
                dirty1[i] <= 0;
                dirty2[i] <= 0;
                lru1[i]   <= 0;
                lru2[i]   <= 0;
                mem1[i]   <= 0;
                mem2[i]   <= 0;
                tag1[i]   <= 0;
                tag2[i]   <= 0;
            end
            _data2mem     <= 0;
            _mwren        <= 0;
            _m_wr_address <= 0;
            _data2cpu     <= 0;
            counter       <= 0;
        end
        else
        begin
            case(cs)
                IDLE:
                begin
                    counter <= 0;
                    if (hit_miss && (rd || wr))
                    begin
                        if (valid1[address[`INDEX]] && (tag1[address[`INDEX]] == address[`TAG]))
                        begin
                            if (rd) // read
                            begin
                                _data2cpu <= mem1[address[`INDEX]];
                            end
                            else    // write
                            begin
                                _data2cpu               <= 32'b0;
                                mem1[address[`INDEX]]   <= data_in_cpu;
                                dirty1[address[`INDEX]] <= 1;
                            end
                            // one for recent used
                            lru1[address[`INDEX]] <= 1;
                            lru2[address[`INDEX]] <= 0;
                        end
                        else
                        begin
                            if (rd) // read
                            begin
                                _data2cpu <= mem2[address[`INDEX]];
                            end
                            else    // write
                            begin
                                _data2cpu               <= 32'b0;
                                mem2[address[`INDEX]]   <= data_in_cpu;
                                dirty2[address[`INDEX]] <= 1;
                            end
                            lru1[address[`INDEX]] <= 0;
                            lru2[address[`INDEX]] <= 1;
                        end
                    end
                    else
                    begin
                        _data2cpu <= 0;
                    end
                end
                MISS:
                begin
                    // read miss, take data from memory
                    counter <= counter + 1;
                    if (rd)
                    begin
                        _data2cpu <= data_in_mem;
                    end
                    else
                    begin
                        _data2cpu <= 0;
                    end
                    // check way 1
                    if (lru1[address[`INDEX]] == 0)
                    begin
                        // if dirty, write back to memory
                        if (dirty1[address[`INDEX]] == 1)
                        begin
                            _m_wr_address <= {tag1[address[`INDEX]],address[`INDEX]};
                            _mwren        <= 1;
                            _data2mem     <= mem1[address[`INDEX]];
                        end
                        // write allocate
                        tag1[address[`INDEX]]   <= address[`TAG];
                        valid1[address[`INDEX]] <= 1;
                        lru1[address[`INDEX]]   <= 1;
                        lru2[address[`INDEX]]   <= 0;
                        if (rd)
                        begin // read miss
                            dirty1[address[`INDEX]] <= 0;
                            mem1[address[`INDEX]]   <= data_in_mem;
                        end
                        else
                        begin // write miss
                            dirty1[address[`INDEX]] <= 1;
                            mem1[address[`INDEX]]   <= data_in_cpu;
                        end
                    end
                    // if all valid, find least recent use
                    // check way 2
                    else if (lru2[address[`INDEX]] == 0)
                    begin
                        // if dirty, write back to memory
                        if (dirty2[address[`INDEX]] == 1)
                        begin
                            _m_wr_address <= {tag1[address[`INDEX]],address[`INDEX]};
                            _mwren        <= 1;
                            _data2mem     <= mem1[address[`INDEX]];
                        end
                        // write allocate
                        tag2[address[`INDEX]]   <= address[`TAG];
                        valid2[address[`INDEX]] <= 1;
                        lru1[address[`INDEX]]   <= 0;
                        lru2[address[`INDEX]]   <= 1;
                        if (rd)
                        begin // read miss
                            dirty2[address[`INDEX]] <= 0;
                            mem2[address[`INDEX]]   <= data_in_mem;
                        end
                        else
                        begin // write miss
                            dirty2[address[`INDEX]] <= 1;
                            mem2[address[`INDEX]]   <= data_in_cpu;
                        end
                    end
                    else
                    begin
                    end
                end
                DONE:
                begin
                    _data2cpu <= 0;
                    counter   <= 0;
                end
            endcase
        end
    end
endmodule
