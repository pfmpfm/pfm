#include "Vtop.h" // 引入Verilator生成的顶层模块的头文件
#include "verilated.h" // 引入Verilator的头文件，包含Verilator模拟所需的基本函数和类
#include <nvboard.h> // 引入nvboard库的头文件，用于硬件模拟

// 定义一个全局的TOP_NAME类型的变量dut，表示待测设备（Device Under Test）
static TOP_NAME dut;

// 声明一个函数，用于将所有引脚绑定到Vtop实例
void nvboard_bind_all_pins(Vtop* top);

// 定义一个函数，用于执行一次模拟周期
static void single_cycle() {
  // 执行一次模拟
  dut.eval();
}

int main(int argc, char** argv) {
  // 将所有引脚绑定到dut
  nvboard_bind_all_pins(&dut);
  // 初始化nvboard
  nvboard_init();

  // 无限循环，持续更新nvboard并执行模拟
  while (1) {
    // 更新nvboard的状态
    nvboard_update();
    // 执行一次模拟周期
    single_cycle();
  }
  return 0;
}

