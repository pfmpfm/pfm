module top(
    input Y0, Y1,
    input [1:0] X0, X1, X2, X3, 
    output wire [1:0] F 
);
    mux4_1 i0 (
        .Y0(Y0), .Y1(Y1),
        .X0(X0), .X1(X1), .X2(X2), .X3(X3),
        .F(F)
    );
endmodule

