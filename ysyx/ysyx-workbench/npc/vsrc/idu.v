/* verilator lint_off UNUSED  */
module idu(
	input  [6:0]opcode,
	input  [11:0]f12,
	output [2:0]alucontrol,
	output regwrite,
	output [2:0]immtype
);
import "DPI-C" function void ebreak();
assign alucontrol=3'b000;
assign regwrite=1;
assign immtype=3'b000;
always @(*) begin
  if(opcode == 7'b1110011 && f12 == 12'h1)begin
    ebreak();
    end
  end
endmodule
/* verilator lint_on UNUSED  */
