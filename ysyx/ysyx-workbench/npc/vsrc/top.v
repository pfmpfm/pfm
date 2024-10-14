/* verilator lint_off UNUSED  */
module top(
	input  clk,
	input  rst,
	input  [31:0]inst,
	input  [31:0]pc
);

import "DPI-C" function void itrace(input int inst);
always @(posedge clk) begin
        itrace(inst);  // 传递 PC 值给 C 函数
end

reg [31:0] rf [31:0]; // 定义寄存器数组
wire [6:0]opcode=inst[6:0];
wire [2:0]alucontrol;
wire regwrite;
wire [2:0]immtype;
reg [31:0]rs1;
wire [4:0]rs1_addr;
wire [31:0]alu_result;
wire [31:0]imm;
wire [4:0]rd=inst[11:7];
wire [11:0]f12;
assign rs1_addr = inst[19:15];
assign rs1      = rf[rs1_addr];
assign f12      = inst[31:20];

idu IDU(
	.opcode(opcode),
	.f12(f12),
	.alucontrol(alucontrol),
	.regwrite(regwrite),
	.immtype(immtype)
);

imm IMM(
	.inst(inst),
	.immtype(immtype),
	.result(imm)
);

alu ALU(
	.rs1(rs1),
	.imm(imm),
	.opcode(opcode),
	.alucontrol(alucontrol),
	.result(alu_result)
);

regfile regfile2(
	.clk(clk),
	.wdata(alu_result),
	.waddr(rd),
	.raddr(rs1_addr),
	.rdata(rs1),	
	.rf(rf),
	.wen(regwrite)
);

endmodule
/* verilator lint_on UNUSED  */
