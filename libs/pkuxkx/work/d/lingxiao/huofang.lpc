// File		: huofang.c
// Created By	: iszt@pkuxkx, 2006-01-26

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "伙房");
	set("long", @LONG
一走进这间屋子，只觉热气扑面而来，几个大蒸笼正在冒着白气，直教人无
法看清其中身着白袍的雪山弟子。灶前堆着几垛柴火，正有人在劈柴(pi 柴)或是
烧火(shao 火)。外面就是凌霄城的饭堂。
LONG);
	set("kitchen", 1);
	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"fantang",
	]));

	setup();
}

void init()
{
	add_action("do_shao", "shao");
	add_action("do_pi", "pi");
}

int do_shao(string arg)
{
	object me = this_player();
	int costj, costq;

	if(arg != "火")
		return notify_fail("你要烧什么？小心别把屋子点着了。\n");
	if(me->query_temp("lingxiao/fantang_job") != "烧火")
		return notify_fail("没人让你来烧火罢？\n");
	if(me->query_temp("lingxiao/fantang_ok"))
		return notify_fail("火已经够旺了，快去覆命罢。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");

	costj = random((int)me->query_con()/3);
	costq = random((int)me->query_str()/3);

	if((int)me->query("jingli") < costj 
		||(int)me->query("qi") < costq)
	{
		message_vision(HIR"$N眼一花，不小心把自己的手烧伤了，痛得昏了过去！\n"NOR, me);
		me->unconcious();
		return 1;
	}

	me->receive_damage("jingli", costj);
	me->receive_damage("qi", costq);

	message_vision("$N凑在灶前，舔柴、鼓风，努力让火烧得更旺。\n", me);
	me->start_busy(1);
	me->add_temp("lingxiao/fantang_times", -1);
	if(!me->query_temp("lingxiao/fantang_times"))
	{
		tell_object(me, "你的任务完成了，快回去覆命罢。\n");
		me->set_temp("lingxiao/fantang_ok", 1);
	}

	return 1;
}

int do_pi(string arg)
{
	object me = this_player();
	object weapon = me->query_temp("weapon");
	int costj, costq;

	if(arg!="柴")
		return notify_fail("你要劈什么？\n");
	if(me->query_temp("lingxiao/fantang_job") != "劈柴")
		return notify_fail("没人让你来劈柴罢？\n");
	if(me->query_temp("lingxiao/fantang_ok"))
		return notify_fail("你已经劈好了，快去覆命罢。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if( !weapon || weapon->query("id") != "chai dao")         
	    return notify_fail("还是先去找一件趁手的工具来吧。\n");

	costj = random((int)me->query_con()/3);
	costq = random((int)me->query_str()/3);

	if((int)me->query("jingli") < costj 
		||(int)me->query("qi") < costq)
	{
		message_vision(HIR"$N手一歪，不小心劈在自己的腿上！\n"NOR, me);
		me->unconcious();
		return 1;
	}

	me->receive_damage("jingli", costj);
	me->receive_damage("qi", costq);

	message_vision("$N摆正一块木头，一刀劈了下去，「哐」的一声，木头被劈为两片。\n", me);
	me->start_busy(1);
	me->add_temp("lingxiao/fantang_times", -1);
	if((int)me->query_skill("blade", 1) < 20 
		&& random(10)>6 )
	{
		write(HIM"你在劈柴中对于刀的用法有些体会!\n"NOR);
		me->improve_skill("blade", (int)(me->query("int") / 10));
	}
	if(!me->query_temp("lingxiao/fantang_times"))
	{
		tell_object(me, "你的任务完成了，快回去覆命罢。\n");
		me->set_temp("lingxiao/fantang_ok", 1);
	}
	return 1;
}