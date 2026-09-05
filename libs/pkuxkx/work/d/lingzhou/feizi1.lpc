// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "皇妃寝宫");
	set("long", @LONG
这里是西夏国皇妃的寝宫。
LONG );
	set("exits", ([
		"west":__DIR__"hougong",
		"east":__DIR__"qifang",
	]));
	set("objects",([
		__DIR__"npc/gongnu":2,
	]));

	setup();
	replace_program(ROOM);
}

