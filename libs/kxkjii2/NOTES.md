

- 2026-10-14：72 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。随后 toolkit_fix.sh 一轮清掉新编译文件露出的警告（nosave 函数 0、空 return 0、未用局部变量 8）。新进程比对 HEAD 与工作树：74 个对象，新增载入 72，回退 0。
