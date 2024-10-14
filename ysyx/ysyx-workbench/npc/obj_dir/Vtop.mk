# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vtop.mk

default: /home/pfm/ysyx/ysyx-workbench/npc/build/top

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vtop
# Module prefix (from --prefix)
VM_MODPREFIX = Vtop
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-I/home/pfm/ysyx/ysyx-workbench/nvboard/usr/include \
	-DTOP_NAME="Vtop" \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	main \
	memory \
	Vtop \
	Vtop__Dpi \
	Vtop__Syms \
	Vtop__Trace__0 \
	Vtop__Trace__0__Slow \
	Vtop___024root__DepSet_h84412442__0 \
	Vtop___024root__DepSet_h84412442__0__Slow \
	Vtop___024root__DepSet_heccd7ead__0 \
	Vtop___024root__DepSet_heccd7ead__0__Slow \
	Vtop___024root__Slow \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	/home/pfm/ysyx/ysyx-workbench/npc \
	/home/pfm/ysyx/ysyx-workbench/npc/csrc \
	/home/pfm/ysyx/ysyx-workbench/npc/obj_dir \


### Default rules...
# Include list of all generated classes
include Vtop_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

main.o: /home/pfm/ysyx/ysyx-workbench/npc/csrc/main.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
memory.o: /home/pfm/ysyx/ysyx-workbench/npc/memory.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop__Dpi.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop__Dpi.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop__Syms.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop__Syms.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop__Trace__0.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop__Trace__0.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop__Trace__0__Slow.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop__Trace__0__Slow.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop___024root__DepSet_h84412442__0.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop___024root__DepSet_h84412442__0.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop___024root__DepSet_h84412442__0__Slow.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop___024root__DepSet_h84412442__0__Slow.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop___024root__DepSet_heccd7ead__0.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop___024root__DepSet_heccd7ead__0.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop___024root__DepSet_heccd7ead__0__Slow.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop___024root__DepSet_heccd7ead__0__Slow.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Vtop___024root__Slow.o: /home/pfm/ysyx/ysyx-workbench/npc/obj_dir/Vtop___024root__Slow.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<

### Link rules... (from --exe)
/home/pfm/ysyx/ysyx-workbench/npc/build/top: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-
