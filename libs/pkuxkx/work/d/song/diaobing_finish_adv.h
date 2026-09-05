#include <ansi.h>
string *departs=({"tianwu","shenwei","majun","bujun"});
string *depart_names=({"天武卫","神卫","马军都","步军都"});
int get_depart_from(object me)
{
	for (int i=0;i<sizeof(departs);i++)
	{
		if (stringp(me->query_temp("songtasks/"+departs[i]+"/huanfang_from")))
		{
			return i;
		}
	}
	return -1;
}
int get_depart_target(object me)
{
	for (int i=0;i<sizeof(departs);i++)
	{
		if (stringp(me->query_temp("songtasks/"+departs[i]+"/huanfang_target")))
		{
			return i;
		}
	}
	return -1;
}
int check_army(object me)
{
	int n;
	object army=me->query_temp("ARMY");
	n=get_depart_from(me);
	if (n<0||n>sizeof(departs)-1)
	return 1;
	if (!army||!army->is_army())
	{
		if (me->query_temp("songtasks/"+departs[n]+"/diaobing"))
		{
			tell_object(me,"你的换防任务失败了。\n");
			me->delete_temp("songtasks");
			tell_object(me,RED"大宋任务失败！\n"NOR);
			DASONG_D->task_finish(me,-3);
			return 1;
		}
		return 1;
	}
	if (me->query_temp("songtasks/"+departs[n]+"/huanfang_target")!=this_object()->query("songtasks/task_myself"))
	return 1;
	if (me->query_temp("songtasks/"+departs[n]+"/1/finish"))
	return 1;
	me->set_temp("songtasks/"+departs[n]+"/1/finish",1);
	tell_object(me,"你完成了换防"+this_object()->query("short")+"的任务，可以回"+depart_names[n]+"复命了。\n");
	army->huanfang(this_object()->query("short"));
	return 1;
}
