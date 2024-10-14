module encode8_3(
    input [7:0] in,
    input en,
    output reg [2:0] out, 
    output reg valid
);
    integer i;
    always @(*) begin
      valid=0;
      if(en) begin
      	out=0;
      	for(i=7;i>=0;i--) begin //从高位开始检查，符合优先编码思想
          if(in[i]) begin
            valid=1;
            out=i[2:0];
            break;
          end
        end
      end
      else out=0;
    end
endmodule

