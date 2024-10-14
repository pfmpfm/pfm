module top(
    input [7:0] in,
    input en,
    output reg [2:0] out, 
    output reg valid,
    output reg [7:0] y
);
    encode8_3 i0(
    .in(in),
    .out(out), 
    .en(en),
    .valid(valid)
    );
    
    seg i1(
    .x({1'b0,out}),
    .y(y)
    );
endmodule

