module shift_register_8(
  input btn,
  output reg [7:0] y
);
  reg y8;
  initial y = 8'b00000001;

  always @(posedge btn) begin
    if(y != 0) begin
      y8 = y[4] ^ y[3] ^ y[2] ^ y[0];
      y <= {y8,y[7:1]};
    end else begin
      y <= 8'b00000001;
    end
  end
endmodule
