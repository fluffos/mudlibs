// File		: stonen3.c
// Created By	: iszt@pkuxkx, 2006-09-05

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。南边是
女弟子休息室，北边是饭堂，女孩子身上的香气和饭菜的香气混合在一起，直让
人陶醉。饭堂里干活的弟子也大概是由于这一缘故，特别卖力，认真程度毫不次
于练剑之时。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"stonee4",
		"north" : __DIR__"fantang",
		"south" : __DIR__"nvxiuxishi",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_breakin", "breakin");
}

int valid_leave(object me, string dir)
{
	if(dir == "south" && me->query("gender") != "女性")
	{
		me->set_temp("lingxiao/breakin_nv", 1);
		return notify_fail(HIY"南边是女弟子休息室！你真的要闯进去"HIG"(breakin)"HIY"么？\n"NOR);
	}
	me->delete_temp("lingxiao/breakin_nv");
	return ::valid_leave(me, dir);
}

int do_breakin(string arg)
{
	object me = this_player();
	object room = load_object(__DIR__"nvxiuxishi");

	if(!me->query_temp("lingxiao/breakin_nv"))
		return 0;

	me->delete_temp("lingxiao/breakin_nv");
	message_vision(HIR"$N不顾南边是女弟子休息室，硬闯了进去！\n"NOR, me);
	me->move(room);
	tell_room(room, HIG+me->name()+"不顾这里是女弟子休息室，硬闯了进来！\n"NOR, ({me}));
	return 1;
}