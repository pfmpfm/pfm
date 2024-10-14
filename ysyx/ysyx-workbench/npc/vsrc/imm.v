/* verilator lint_off UNUSED  */
module imm(
	input  [31:0]inst,
	input  [2:0]immtype,
	output [31:0]result
);
assign result={20'b0,inst[31:20]};

endmodule
/* verilator lint_on UNUSED  */
