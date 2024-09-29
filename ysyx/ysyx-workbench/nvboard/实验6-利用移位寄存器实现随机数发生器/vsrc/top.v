module top(
  input btn,
  output reg [7:0] y,
  output [7:0] seg1,
  output [7:0] seg0
);
wire [3:0] y0 = y[7:4];
wire [3:0] y1 = y[3:0];

  shift_register_8 i0(
    .btn(btn),
    .y(y)
  );
  
  seg i1(
    .x(y0),
    .y(seg1)
  );
  
  seg i2(
    .x(y1),
    .y(seg0)  
  );

endmodule

