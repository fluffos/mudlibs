// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "皇宫广场");
	set("long", @LONG
这里是西夏皇宫的广场。
LONG );
	set("exits", ([
		"south"  : __DIR__"gonggate",
		"north":__DIR__"zhengdian",
		"east":__DIR__"chemafang",
		"west":__DIR__"weishifang",
	]));
	set("objects", ([
		__DIR__"npc/gongweishi" :2,
	]));
	setup();
	replace_program(ROOM);
}

