// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "皇后寝宫");
	set("long", @LONG
这里是西夏皇后的寝宫。
LONG );
	set("exits", ([
		"south"  : __DIR__"houdian",
		"north":__DIR__"zhulin1",
		"east":__DIR__"feizi1",
		"west":__DIR__"feizi2",
	]));
	set("objects", ([
		__DIR__"npc/gongnu" :2,
	]));
	setup();
	replace_program(ROOM);
}

