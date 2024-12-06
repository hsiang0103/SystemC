module SRAM (input wire clk,
             input wire rden,
             input wire wren,
             input wire [15:0] rdaddress,
             input wire [15:0] wraddress,
             input wire [31:0] write_data,
             output reg [31:0] read_data);
    
    reg [7:0] mem [0:65535];
    
    //read//
    always @(*)
    begin
        if (rden)
        begin
            read_data        <= mem[rdaddress];
            read_data[15:8]  <= mem[rdaddress+1];
            read_data[23:16] <= mem[rdaddress+2];
            read_data[31:24] <= mem[rdaddress+3];
        end
    end
    //write//
    always @(posedge clk)
    begin
        if (wren)
        begin
            mem[wraddress]   <= write_data[7:0];
            mem[wraddress+1] <= write_data[15:8];
            mem[wraddress+2] <= write_data[23:16];
            mem[wraddress+3] <= write_data[31:24];
        end
    end
    /*
     always @(posedge clk) begin
     case(w_en)
     4'b1111: begin
     mem[address]   <= pass[7:0];
     mem[address+1] <= pass[15:8];
     mem[address+2] <= pass[23:16];
     mem[address+3] <= pass[31:24];
     end
     4'b0011: begin
     mem[address]   <= pass[7:0];
     mem[address+1] <= pass[15:8];
     end
     4'b0001: begin
     mem[address] <= pass[7:0];
     end
     endcase
     end*/
endmodule
