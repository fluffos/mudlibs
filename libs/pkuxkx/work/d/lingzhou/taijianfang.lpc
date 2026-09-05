// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "太监宿处");
	set("long", @LONG
这里是西夏国皇宫太监们的住宿之处。
LONG );
	set("exits", ([
		"east":__DIR__"shuyuan",
		"west":__DIR__"lenggong",
	]));
	set("objects",([
		__DIR__"npc/taijian":4,
	]));

	setup();
	replace_program(ROOM);
}

