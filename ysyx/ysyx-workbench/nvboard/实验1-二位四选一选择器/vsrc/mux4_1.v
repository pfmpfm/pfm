module mux4_1(
    input Y0, Y1,
    input [1:0] X0, X1, X2, X3, 
    output wire [1:0] F 
);

assign F = Y0 ? (Y1 ? X3 : X2) : (Y1 ? X1 : X0);//三元运算符

endmodule

