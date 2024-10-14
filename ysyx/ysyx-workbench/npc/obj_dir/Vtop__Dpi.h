// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/pfm/ysyx/ysyx-workbench/npc/vsrc/idu.v:9:30
    extern void ebreak();
    // DPI import at /home/pfm/ysyx/ysyx-workbench/npc/vsrc/top.v:8:30
    extern void itrace(int inst);

#ifdef __cplusplus
}
#endif

#endif  // guard
