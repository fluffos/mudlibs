// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include "/d/menggu/entry_migong.h"
#include <ansi.h>
void create()
{
	set("short", "大石");
	set("long", @LONG
这是一块几乎完全平整，十丈见方的石台，你不由感慨大自然的造化之力。
LONG
	);
        set("outdoors", "dongtianmu");

	set("exits", ([
		"westup" : __DIR__"shanlue1",
		//"up" : __DIR__"fenghuang2",
		//"northeast" : __DIR__"wall1",
		//"west" : __DIR__"wall1",
	]));

	set("objects", ([
		__DIR__"npc/yaoshang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("entry_direction","westup");
    set("migong","/d/southmountain/dongtianmu/dongtianmu");
    set("migong_posi","east");
    set("look_refuse_msg","东天目山不高，但这时雾气太重，看不清楚。\n");
    set("enter_refuse_msg","东天目山这时雾气太重，进山不太容易。\n");
	setup();
}

void init()
{
	add_action("do_jump","jump");
	add_action("do_look",({"look","l"}));
}

int do_jump(string arg)
{
	object me=this_player();
	if (me->is_busy()||me->is_fighting())
	return notify_fail("你正忙着呢。\n");
	if (!arg||arg!="east")
	return 0;
	message_vision(HIC+"$N"+HIC+"向着东面奋力一跃。\n"+NOR,me);
	if (me->query_skill("dodge",1)<200||me->query_dex()<40)
	{
		message_vision("可惜东面地势比这里高多了，$N勉强跳了过去，重重撞在一块石头上。\n",me);
		me->unconcious();
	}
	me->move(__DIR__"fenghuangxi");
	return 1;
}
