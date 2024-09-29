all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator -Wall --cc --exe --build --trace ./vsrc/on-off_switch.c ./vsrc/top.v
	cd ./vsrc
	make -C obj_dir -f Vtop.mk Vtop
	gtkwave ./vsrc/wave.vcd

	

include ../Makefile
