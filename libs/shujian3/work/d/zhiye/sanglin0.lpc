// 桑林外
// sanglin0.c
// augx@sj 10/17/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","桑林外");
	set("long",
"这是一片范围极大的桑树林，有很多人在此处养蚕，很是热闹。因为树林
范围极大，不熟悉此处的人很容易迷失方向，好在官府已经在林边路口竖立了
指示牌以指明方向，同时还派巡捕巡查山路，防止凶杀事件。
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"south"		: "/d/changan/northroad4",
		"northwest"	: __DIR__"sanglin1",
		"southeast"	: __DIR__"sanglin2",
		"southwest"	: __DIR__"sanglin3",
	]));
	
	set("outdoors", "长安郊外");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}

int valid_leave(object me, string dir)
{
	if( dir == "south" )
		me->delete_temp("sanglin1");
	else
		me->set_temp("sanglin1",random(4));

	if ( me->query("no_quest") && dir != "south")
		return notify_fail("");

	return ::valid_leave(me , dir);
}
