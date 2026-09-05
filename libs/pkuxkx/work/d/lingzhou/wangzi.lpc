// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "王子寝宫");
	set("long", @LONG
这里是西夏国王子的寝宫。
LONG );
	set("exits", ([
		"east":__DIR__"zhulin1",
		"west":__DIR__"xuetang",
	]));
	set("objects",([
		__DIR__"npc/taijian":2,
	]));

	setup();
	replace_program(ROOM);
}

