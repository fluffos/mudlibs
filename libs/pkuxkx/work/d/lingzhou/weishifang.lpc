// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "卫士宿处");
	set("long", @LONG
这里是西夏国皇宫的卫士们住宿的地方。
LONG
);
	set("exits", ([
		"east":__DIR__"gongsquare",
		"north":__DIR__"huafang",
	]));
	set("objects",([
		__DIR__"npc/gongweishi":5
	]));
	setup();
	replace_program(ROOM);
}

