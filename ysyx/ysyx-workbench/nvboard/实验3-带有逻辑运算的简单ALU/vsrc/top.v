module top(
  input [3:0] a,b,
  input [2:0] choose,
  output reg [3:0] c,
  output reg zero,
  output reg overflow,
  output reg cin
);
    ALU i0(
      .a(a),
      .b(b),
      .choose(choose),
      .c(c),
      .zero(zero),
      .overflow(overflow),
      .cin(cin)
    );

endmodule

