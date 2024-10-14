/* verilator lint_off UNUSED  */
module alu(
	input  [31:0]rs1,
	input  [31:0]imm,
	input	 [6:0]opcode,
	input  [2:0]alucontrol,
	output [31:0]result
);
assign result=imm+rs1;


endmodule
/* verilator lint_on UNUSED  */
