// quest.c

#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,obj;
	mapping q;
	string master,str;
	if (me->query_condition("jjfb"))
		tell_object(me, HIG"你的狂盗谷副本时间还有"+chinese_number(me->query_condition("jjfb")/6)+"分钟。"NOR"\n");
	if (me->query("shimen/today"))
		tell_object(me, HIG"你本周已经做了"+chinese_number(me->query("shimen/today"))+"个师门任务了。"NOR"\n");
	if (me->query_condition("db_jifen"))
		tell_object(me, HIG"你的双倍点券卡时间还有"+chinese_number(me->query_condition("db_jifen")/6)+"分钟。"NOR"\n");
	if (me->query_condition("db_exp"))
		tell_object(me, HIG"你的天灵丹时间还有"+chinese_number(me->query_condition("db_exp")/6)+"分钟。"NOR"\n");
	if (me->query_condition("db_exp2"))
		tell_object(me, HIG"你的玄灵丹时间还有"+chinese_number(me->query_condition("db_exp2")/6)+"分钟。"NOR"\n");
	if (me->query_condition("db_exp3"))
		tell_object(me, HIG"你的麒麟丹时间还有"+chinese_number(me->query_condition("db_exp3")/6)+"分钟。"NOR"\n");

if (me->query("auto_kill_quest_npc") && me->query("quest/id")) {
	if (objectp(present(me->query("quest/id"),environment(me)))) {
		me->force_me("kill " + me->query("quest/id"));
		return 1;
	}
}






	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quest  这个指令可以用来向你的门派的掌门或世家长辈
领取任务，如果不加任何参数则显示出你当前的任务。
HELP );
	return 1;
}
