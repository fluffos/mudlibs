// /cmds/usr/locate.c
//Made by jason@pkuxkx
//2001.1.3
#include <ansi.h>
int main(object me,string arg)
{
	mixed output;
	string ow,na;
	
	if (me->query("antirobot/deactivity") > 2) message("vision",HIR"Becool突然从地下钻出来揪着你的耳朵喊：“小样儿，是机器人把！”\n"NOR,me);

	if(!arg||arg=="")
		return notify_fail("你要寻找什么的方位？\n");
//        log_file("user/locate.log",sprintf("[%s] %s locate %s\n",ctime(time()),geteuid(me),arg));
	if(me->is_busy()) return notify_fail("先忙完手头的事情吧！\n");
	if (me->query("jing") < 50) return notify_fail("你的无法集中精神确定方位。\n");
	if(sscanf(arg,"%s的%s",ow,na)!=2) 
		return notify_fail("没有这样东西。\n");
	output=TASK_D->query_location(arg);
	me->set_temp("task/last_locate",time());
	me->add("jing",-30);
	if(intp(output)&&output<0)
		return notify_fail("无法确定"+arg+"的方位\n");
	if(stringp(output))
	{
		write(output);
		me->start_busy(1);
		return 1;
	}
	return 0;
}
int help(object me)
{
        write(@HELP
指令格式: locate <物品名称>
 
物品名称为用task命令所得到的列表中的物品。
 
范例:locate 李莫愁的毒经
李莫愁的毒经在一个有着west的出口的地方。
这个地方的描述中含有这样的字眼：好好,他一
 
这个指令是做task的必须。通过描述中的字眼找到物品
还给对应的npc，即完成了task任务的第一步。
 
相关指令: task quest
HELP
    );
    return 1;
}
