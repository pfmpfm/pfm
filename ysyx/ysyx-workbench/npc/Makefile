#************************************  verilator  ***************************************************************
VERILATOR += verilator
# Generate C++ in executable form
VERILATOR_FLAGS += -cc --exe
# Generate makefile dependencies (not shown as complicates the Makefile)
#VERILATOR_FLAGS += -MMD
# Optimize
VERILATOR_FLAGS += -x-assign fast
# Warn abount lint issues; may not want this on less solid designs
VERILATOR_FLAGS += -Wall
# Make waveforms
VERILATOR_FLAGS += --trace
# Check SystemVerilog assertions
VERILATOR_FLAGS += --assert
# Generate coverage analysis
VERILATOR_FLAGS += --coverage
# Run Verilator in debug mode
#VERILATOR_FLAGS += --debug
# Add this trace to get a backtrace in gdb
#VERILATOR_FLAGS += --gdbbt

# Input files for Verilator
VERILATOR_INPUT += ./vsrc/*.v ./csrc/*.cpp 

WAVE=./logs/wave.vcd
#***************************************************************************************************************

#****************************************** nvboard ****************************************************************
TOP_NAME = top
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

BUILD_DIR = ./build
OBJ_DIR = ./obj_dir
BIN = $(BUILD_DIR)/$(TOP_NAME)

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)

VERILATOR_CFLAGS += -MMD --trace --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert 

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) $(abspath ./) -name "*.c" -or -name "*.cc" -or -name "*.cpp")


# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOP_NAME)\""
LDFLAGS += -lSDL2 -lSDL2_image
#***************************************************************************************************************

$(shell mkdir -p $(BUILD_DIR))

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

default: run

t_shell:
	sudo chmod -R 777 ./t_shell/*

sim: clean
	@echo "-- VERILATE ----------------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INPUT)
	@echo "-- BUILD -------------------"
	make -j -C obj_dir -f Vtop.mk Vtop
	@echo "-- RUN & WAVE --------------"
	@rm -rf logs
	@mkdir -p logs
	./obj_dir/Vtop 
	@echo "-- DONE --------------------"

wave:
	gtkwave $(WAVE)

clean:
	rm -rf ./logs ./obj_dir $(BUILD_DIR)

yosys_t:
	cat ./yosys/yosys.txt | yosys

$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

$(BIN): $(VSRCS) $(CSRCS) 
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOP_NAME) $^ \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

run: $(BIN)
	@$^

.PHONY:default sim run clean t_shell yosys_t
