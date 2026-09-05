// set.c
// Modified by iszt@pkuxkx, 2007-03-11

#include <ansi.h>


inherit F_CLEAN_UP;

int main(object me)
{
//   me->set("env/action4", "完成");
//	me->set_temp("force_receive_msg",1);
   write("设定环境变量：action8 = 完成\n");
//	me->delete_temp("force_receive_msg");
   return 1;
}

int help()
{
        write(@TEXT
指令格式：setact0

这个指令让你设定action0环境变量为完成。

取消变量设定请用 unset 指令。这个命令没有明显的CD。

至於有哪些环境变量可以设定，请见 help settings。
TEXT
);
        return 1;
}
