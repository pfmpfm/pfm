// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

void Vtop___024root____Vdpiimwrap_top__DOT__IDU__DOT__ebreak_TOP();

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    if ((IData)((0x100073U == (0xfff0007fU & vlSelf->inst)))) {
        Vtop___024root____Vdpiimwrap_top__DOT__IDU__DOT__ebreak_TOP();
    }
    vlSelf->top__DOT__rs1 = vlSelf->top__DOT__rf[(0x1fU 
                                                  & (vlSelf->inst 
                                                     >> 0xfU))];
    vlSelf->top__DOT__alu_result = ((vlSelf->inst >> 0x14U) 
                                    + vlSelf->top__DOT__rs1);
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__itrace_TOP(IData/*31:0*/ inst);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    Vtop___024root____Vdpiimwrap_top__DOT__itrace_TOP(vlSelf->inst);
    vlSelf->top__DOT____Vcellout__regfile2__rf[(0x1fU 
                                                & (vlSelf->inst 
                                                   >> 7U))] 
        = vlSelf->top__DOT__alu_result;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/pfm/ysyx/ysyx-workbench/npc/vsrc/top.v", 2, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/pfm/ysyx/ysyx-workbench/npc/vsrc/top.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/pfm/ysyx/ysyx-workbench/npc/vsrc/top.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
