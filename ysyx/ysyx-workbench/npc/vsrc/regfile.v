/* verilator lint_off UNUSED */
module regfile (
  input clk,
  input  [31:0] wdata,
  input  [4:0] waddr,
  input  [4:0] raddr,
  output reg [31:0] rdata,
  output reg [31:0] rf [31:0], 
  input  wen
);
    
  always @(posedge clk) begin
    if (wen) 
      rf[waddr] = wdata;
    else 
      rdata = rf[raddr];
  end
endmodule
/* verilator lint_on UNUSED */

