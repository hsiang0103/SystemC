#include "systemc.h"
#include "timer.h"

int sc_main(int argc, char **argv)
{
    sc_signal<bool> start;
    sc_signal<bool> timeout;
    sc_clock clk("clock", 10, SC_NS);

    timer t1("timer");
    t1.start(start);
    t1.timeout(timeout);
    t1.clock(clk);


    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    sc_trace(tf, clk, "clock");
    sc_trace(tf, start, "start");
    sc_trace(tf, timeout, "timeout");

    // Local variable for tracing the count
    sc_trace(tf, t1.count, "count");

    // Simulation logic
    start.write(0);      
    sc_start(30, SC_NS); 

    start.write(1);      
    sc_start(40, SC_NS); 

    start.write(0);      
    sc_start(30, SC_NS); 

    start.write(1);      
    sc_start(30, SC_NS); 

    start.write(0);      
    sc_start(170, SC_NS); 

    // End simulation
    sc_close_vcd_trace_file(tf);
    return 0;
}
