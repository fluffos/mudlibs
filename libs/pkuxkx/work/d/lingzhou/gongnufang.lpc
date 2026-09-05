// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "宫女宿处");
	set("long", @LONG
这里是西夏皇宫宫女们住宿的地方。
LONG );
	set("exits", ([
		"west":__DIR__"shuyuan",
		"east":__DIR__"yushi",
	]));
	set("objects",([
		__DIR__"npc/gongnu":5,
	]));

	setup();
	replace_program(ROOM);
}

