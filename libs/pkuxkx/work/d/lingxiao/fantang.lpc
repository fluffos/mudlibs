// File		: fantang.c
// Created By	: iszt@pkuxkx, 2006-01-26

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "饭堂");
	set("long", @LONG
这里便是凌霄城众弟子吃饭的地方，屋子里摆了十几张桌子，桌面擦的露出
木头本来的颜色。虽然这里供应的都不是山珍海味，但学武之人也没有那么多讲
究，只要填饱肚子就行。木柴燃烧时发出的劈啪声和锅碗瓢盆碰撞的声音混在一
起，一个肥肥矮矮的中年人正指挥着几个弟子干活。往里是伙房。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"huofang",
		"south" : __DIR__"stonen5",
	]));
	set("objects", ([
		__DIR__"npc/liwanshan" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_shoushi", "shoushi");
	add_action("do_zhengli", "zhengli");
}

int do_shoushi(string arg)
{
	object me = this_player();
	object room;

	if(arg!="碗筷")
		return notify_fail("你要收拾什么？\n");
	if(me->query_temp("lingxiao/fantang_job") != "收拾碗筷")
		return notify_fail("没人让你来收拾碗筷罢？\n");
	if(me->query_temp("lingxiao/fantang_ok"))
		return notify_fail("你已经收拾好了，快去覆命罢。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	message_vision("$N开始收拾桌上的碗筷。\n", me);
	me->start_busy(999);
	call_out("end_shoushi", 5+random(5), me);
	return 1;
}

int end_shoushi(object me)
{
	object room;

	if(!me)
		return 1;
	me->receive_damage("qi", 10);
	if(me->query("qi") < 0)
	{
		message_vision("$N一不小心，被绊了个跟头，倒在地上昏了过去。\n", me);
		return 1;
	}
	message_vision("$N拿起收拾好的碗筷，往伙房走去。\n", me);
	if(!( room = find_object(__DIR__"huofang")) )
		room = load_object(__DIR__"huofang");
	me->move(room);
	message_vision("$N将碗筷放下，擦了擦汗。\n", me);
	me->start_busy(1);

	me->add_temp("lingxiao/fantang_times", -1);
	if(!me->query_temp("lingxiao/fantang_times"))
	{
		tell_object(me, "你的任务完成了，快回去覆命罢。\n");
		me->set_temp("lingxiao/fantang_ok", 1);
	}
}

int do_zhengli(string arg)
{
	object me = this_player();
	int costj, costq;

	if(arg != "桌椅")
		return notify_fail("你要整理什么？\n");
	if(me->query_temp("lingxiao/fantang_job") != "整理桌椅")
		return notify_fail("没人让你来整理桌椅罢？\n");
	if(me->query_temp("lingxiao/fantang_ok"))
		return notify_fail("桌椅已经整理好了，快去覆命罢。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");

	costj = random((int)me->query_con()/3);
	costq = random((int)me->query_str()/3);

	if((int)me->query("jingli") < costj 
		||(int)me->query("qi") < costq)
	{
		message_vision(HIR"$N眼一花，不小心碰倒了壁柜，被砸昏了过去！\n"NOR, me);
		me->unconcious();
		return 1;
	}

	me->receive_damage("jingli", costj);
	me->receive_damage("qi", costq);

	message_vision("$N整理着饭堂中的桌椅。\n", me);
	me->start_busy(5+random(4));
	me->add_temp("lingxiao/fantang_times", -1);
	if(!me->query_temp("lingxiao/fantang_times"))
	{
		tell_object(me, "你的任务完成了，快回去覆命罢。\n");
		me->set_temp("lingxiao/fantang_ok", 1);
	}

	return 1;
}