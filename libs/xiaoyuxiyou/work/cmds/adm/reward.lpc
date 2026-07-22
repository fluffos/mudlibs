//调整奖励基数
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	int t,time;
	if( !arg || sscanf(arg,"%d %d",t,time)!=2 )
		return notify_fail("指令格式 : reward <数字> <时间>\n");
	if( !QUEST_D->set_job_reward_flag(t,time,me) )
		return notify_fail("调整失败，必需是100-500之间的数字，24小时之内的时间，单位为秒。\n");
	write("ok\n");	
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : reward <数字 时间>
 
这个指令调整全局奖励基数，50为一半，100为正常，200为双倍
HELP
    );
    return 1;
}


