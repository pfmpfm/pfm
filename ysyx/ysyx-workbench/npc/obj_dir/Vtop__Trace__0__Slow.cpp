// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+65,"clk", false,-1);
    tracep->declBit(c+66,"rst", false,-1);
    tracep->declBus(c+67,"inst", false,-1, 31,0);
    tracep->declBus(c+68,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+65,"clk", false,-1);
    tracep->declBit(c+66,"rst", false,-1);
    tracep->declBus(c+67,"inst", false,-1, 31,0);
    tracep->declBus(c+68,"pc", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+76,"alucontrol", false,-1, 2,0);
    tracep->declBit(c+77,"regwrite", false,-1);
    tracep->declBus(c+76,"immtype", false,-1, 2,0);
    tracep->declBus(c+70,"rs1", false,-1, 31,0);
    tracep->declBus(c+71,"rs1_addr", false,-1, 4,0);
    tracep->declBus(c+72,"alu_result", false,-1, 31,0);
    tracep->declBus(c+73,"imm", false,-1, 31,0);
    tracep->declBus(c+74,"rd", false,-1, 4,0);
    tracep->declBus(c+75,"f12", false,-1, 11,0);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+70,"rs1", false,-1, 31,0);
    tracep->declBus(c+73,"imm", false,-1, 31,0);
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+76,"alucontrol", false,-1, 2,0);
    tracep->declBus(c+72,"result", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("IDU ");
    tracep->declBus(c+69,"opcode", false,-1, 6,0);
    tracep->declBus(c+75,"f12", false,-1, 11,0);
    tracep->declBus(c+76,"alucontrol", false,-1, 2,0);
    tracep->declBit(c+77,"regwrite", false,-1);
    tracep->declBus(c+76,"immtype", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("IMM ");
    tracep->declBus(c+67,"inst", false,-1, 31,0);
    tracep->declBus(c+76,"immtype", false,-1, 2,0);
    tracep->declBus(c+73,"result", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile2 ");
    tracep->declBit(c+65,"clk", false,-1);
    tracep->declBus(c+72,"wdata", false,-1, 31,0);
    tracep->declBus(c+74,"waddr", false,-1, 4,0);
    tracep->declBus(c+71,"raddr", false,-1, 4,0);
    tracep->declBus(c+70,"rdata", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+33+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->declBit(c+77,"wen", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__rf[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__rf[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__rf[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__rf[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__rf[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__rf[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__rf[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__rf[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__rf[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__rf[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__rf[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__rf[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__rf[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__rf[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__rf[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__rf[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__rf[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__rf[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__rf[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__rf[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__rf[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__rf[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__rf[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__rf[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__rf[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__rf[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__rf[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__rf[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__rf[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__rf[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__rf[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__rf[31]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT____Vcellout__regfile2__rf[0]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT____Vcellout__regfile2__rf[1]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT____Vcellout__regfile2__rf[2]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT____Vcellout__regfile2__rf[3]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT____Vcellout__regfile2__rf[4]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT____Vcellout__regfile2__rf[5]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT____Vcellout__regfile2__rf[6]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT____Vcellout__regfile2__rf[7]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT____Vcellout__regfile2__rf[8]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT____Vcellout__regfile2__rf[9]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT____Vcellout__regfile2__rf[10]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT____Vcellout__regfile2__rf[11]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT____Vcellout__regfile2__rf[12]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT____Vcellout__regfile2__rf[13]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT____Vcellout__regfile2__rf[14]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT____Vcellout__regfile2__rf[15]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT____Vcellout__regfile2__rf[16]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT____Vcellout__regfile2__rf[17]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT____Vcellout__regfile2__rf[18]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT____Vcellout__regfile2__rf[19]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT____Vcellout__regfile2__rf[20]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT____Vcellout__regfile2__rf[21]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT____Vcellout__regfile2__rf[22]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT____Vcellout__regfile2__rf[23]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT____Vcellout__regfile2__rf[24]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT____Vcellout__regfile2__rf[25]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT____Vcellout__regfile2__rf[26]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT____Vcellout__regfile2__rf[27]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT____Vcellout__regfile2__rf[28]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT____Vcellout__regfile2__rf[29]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT____Vcellout__regfile2__rf[30]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT____Vcellout__regfile2__rf[31]),32);
    bufp->fullBit(oldp+65,(vlSelf->clk));
    bufp->fullBit(oldp+66,(vlSelf->rst));
    bufp->fullIData(oldp+67,(vlSelf->inst),32);
    bufp->fullIData(oldp+68,(vlSelf->pc),32);
    bufp->fullCData(oldp+69,((0x7fU & vlSelf->inst)),7);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__rs1),32);
    bufp->fullCData(oldp+71,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullIData(oldp+72,(((vlSelf->inst >> 0x14U) 
                              + vlSelf->top__DOT__rs1)),32);
    bufp->fullIData(oldp+73,((vlSelf->inst >> 0x14U)),32);
    bufp->fullCData(oldp+74,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullSData(oldp+75,((vlSelf->inst >> 0x14U)),12);
    bufp->fullCData(oldp+76,(0U),3);
    bufp->fullBit(oldp+77,(1U));
}
