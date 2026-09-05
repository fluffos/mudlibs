// zhuicha.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
int help(object me);
int zhuicha(object me,string arg)
{
	object env,target;
	if (no_user(me))
	return 1;
	tell_object(me,HIW+"派出追查"+arg+"的人陆续回报：\n"+NOR);
	target=find_player(arg);
	if (!target)
	{
		target=find_living(arg);
		if (!target)
		{
			tell_object(me,arg+"极有可能已经不在人世了。\n");
			return 1;
		}
	}
	if (wizardp(target))
	{
		tell_object(me,"神仙的事，凡人掺和什么。\n");
		return 1;
	}
	env=environment(target);
	if (!env)
	{
		tell_object(me,"这个人恐怕没人能找到。\n");
		return 1;
	}
	else
	{
		me->add("song/zhuicha/times",1);
		tell_object(me,target->name()+"现在躲在"+HBWHT+HIR+env->query("short")+NOR+"，那里的描述是：\n    "+env->query("long"));
		return 1;
	}
}
int main(object me,string arg)
{
	string benefit="zhuicha",type="day";
	int times,period;
	if (arg=="-h")
	return help(me);
	if (!arg||arg=="")
	{
		tell_object(me,"你要追查什么？\n");
		return 1;
	}
	if (!me->query("song/pro"))
	return 0;
	if (DASONG_D->get_my_pin(me)&&DASONG_D->get_my_pin(me)>4)
	{
		tell_object(me,"只有四品官员及以上才可以调动朝廷的力量追查某人！\n");
		return 1;
	}
	song_cycle(me,type,benefit);
	if (arg==me->query("id"))
	{
		tell_object(me,"你要追查自己？\n");
		return 1;
	}
	if (DASONG_D->identification(me,({"刑部尚书"})))
	{
		times=3;
		period=-10;
	}
	if (DASONG_D->identification(me,({"刑部左侍郎","刑部右侍郎"})))
	{
		times=1;
		period=-6;
	}
	times=times+8-(int)DASONG_D->get_my_pin(me);
	if (DASONG_D->get_my_pin(me)&&me->query("song/zhuicha/times")>times)
	{
		tell_object(me,"今日你可以动员的力量已经全部派出追查了。\n");
		return 1;
	}
	message_vision(HIW"$N派出大量人手开始在各地追查"+arg+"的消息。\n"NOR,me);
	period=period+15+random(15);
	call_out("zhuicha",period,me,arg);
	return 1;
}
int help(object me)
{
    write("
指令格式 : song zhuicha <id>
动用大宋力量，追查某玩家或NPC。
"    );
    return 1;
}
