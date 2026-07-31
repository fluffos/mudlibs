// time.c

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{

	write(sprintf("%s现在的时间是：\n%s。\n" ,HIR + LOCAL_MUD_NAME() + NOR,NATURE_D->game_time(),));	
	write (HIY"你的三倍潜能时间还剩："+CHINESE_D->chinese_time(me->query("qnvip/times"))+ "。"NOR"\n");	

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
