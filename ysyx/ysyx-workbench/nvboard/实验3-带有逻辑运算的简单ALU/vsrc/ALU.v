module ALU(
  input [3:0] a,b,
  input [2:0] choose,
  output reg [3:0] c,
  output reg zero,  //结果是否为零
  output reg overflow,
  output reg cin
);

always @(*) begin
  assign zero=0;
  assign overflow=0;
  assign cin=0;
  assign c=0;

  if(choose==3'b000) begin //加法
    {cin,c}=a+b;
    assign zero=~(|c);//～（0按位或c）
    assign overflow=(a[3]==b[3])&&(c[3]!=a[3]);//如果两个参加加法运算的变量符号相同，而运算结果的符号与其不相同，则运算结果不准确，产生溢出
  end
  else if(choose==3'b001) begin  //减法
    {cin,c}=a-b;
    assign zero=~(|c);
    assign overflow=(a[3]!=b[3])&&(c[3]!=a[3]);//如果两个参加减法运算的变量符号不相同，而运算结果的符号与其不相同，则运算结果不准确，产生溢出
  end
  else if(choose==3'b010) begin  //取反
    assign c=~a;
  end
  else if(choose==3'b011) begin  //与
    assign c=a&b;
  end
  else if(choose==3'b100) begin  //或
    assign c=a|b; 
  end
  else if(choose==3'b101) begin  //异或
    assign c=a^b;   
  end
  else if(choose==3'b110) begin  //比较大小——If A<B then out=1; else out=0;
    if(a[3]<b[3])  c=0;
    else if(a[3]>b[3])  c=1;
    else if(a<b&&a[3]==b[3]==0)  c=1;   
    else if(a<b&&a[3]==b[3]==1)  c=1; 
    else  c=0;  
  end
  else if(choose==3'b111) begin  //判断相等——If A==B then out=1; else out=0;
    if(a==b)  c=1;
    else  c=0;   
  end
end
endmodule
