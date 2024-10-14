// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/pfm/ysyx/ysyx-workbench/npc/vsrc/top.v", 2, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root____Vdpiimwrap_top__DOT__IDU__DOT__ebreak_TOP();

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((IData)((0x100073U == (0xfff0007fU & vlSelf->inst)))) {
        Vtop___024root____Vdpiimwrap_top__DOT__IDU__DOT__ebreak_TOP();
    }
    vlSelf->top__DOT__rf[0x1fU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x1fU];
    vlSelf->top__DOT__rf[0x1eU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x1eU];
    vlSelf->top__DOT__rf[0x1dU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x1dU];
    vlSelf->top__DOT__rf[0x1cU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x1cU];
    vlSelf->top__DOT__rf[0x1bU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x1bU];
    vlSelf->top__DOT__rf[0x1aU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x1aU];
    vlSelf->top__DOT__rf[0x19U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x19U];
    vlSelf->top__DOT__rf[0x18U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x18U];
    vlSelf->top__DOT__rf[0x17U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x17U];
    vlSelf->top__DOT__rf[0x16U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x16U];
    vlSelf->top__DOT__rf[0x15U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x15U];
    vlSelf->top__DOT__rf[0x14U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x14U];
    vlSelf->top__DOT__rf[0x13U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x13U];
    vlSelf->top__DOT__rf[0x12U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x12U];
    vlSelf->top__DOT__rf[0x11U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x11U];
    vlSelf->top__DOT__rf[0x10U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0x10U];
    vlSelf->top__DOT__rf[0xfU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0xfU];
    vlSelf->top__DOT__rf[0xeU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0xeU];
    vlSelf->top__DOT__rf[0xdU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0xdU];
    vlSelf->top__DOT__rf[0xcU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0xcU];
    vlSelf->top__DOT__rf[0xbU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0xbU];
    vlSelf->top__DOT__rf[0xaU] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0xaU];
    vlSelf->top__DOT__rf[9U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [9U];
    vlSelf->top__DOT__rf[8U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [8U];
    vlSelf->top__DOT__rf[7U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [7U];
    vlSelf->top__DOT__rf[6U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [6U];
    vlSelf->top__DOT__rf[5U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [5U];
    vlSelf->top__DOT__rf[4U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [4U];
    vlSelf->top__DOT__rf[3U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [3U];
    vlSelf->top__DOT__rf[2U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [2U];
    vlSelf->top__DOT__rf[1U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [1U];
    vlSelf->top__DOT__rf[0U] = vlSelf->top__DOT____Vcellout__regfile2__rf
        [0U];
    vlSelf->top__DOT__rs1 = vlSelf->top__DOT__rf[(0x1fU 
                                                  & (vlSelf->inst 
                                                     >> 0xfU))];
    vlSelf->top__DOT__alu_result = ((vlSelf->inst >> 0x14U) 
                                    + vlSelf->top__DOT__rs1);
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->inst = 0;
    vlSelf->pc = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__rf[__Vi0] = 0;
    }
    vlSelf->top__DOT__rs1 = 0;
    vlSelf->top__DOT__alu_result = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT____Vcellout__regfile2__rf[__Vi0] = 0;
    }
    vlSelf->__Vtrigrprev__TOP__clk = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
