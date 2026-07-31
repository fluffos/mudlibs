// time.c
#include <localtime.h>
#define C(x) CHINESE_D->chinese_number(x)
inherit F_CLEAN_UP;
int main(object me, string arg)
{
      mixed *local = localtime(time());
        write("现在泥潭时间是：" + NATURE_D->game_time() + "。\n");
      write("现实世界时间是：公元"+sprintf("%s年%s月%s日%s时%s分%s秒",C(local[LT_YEAR]),C(local[LT_MON]+1),C(local[LT_MDAY]),C(local[LT_HOUR]),C(local[LT_MIN]+1),C(local[LT_SEC]+1))+"\n");
	return 1;
}
int help(object me)
{
     write(@HELP
指令格式: time
这个指令让你(你)知道现在的时辰。
HELP
    );
    return 1;
}
