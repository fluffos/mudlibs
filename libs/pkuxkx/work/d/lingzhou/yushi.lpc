// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "浴室");
	set("long", @LONG
这里是西夏皇宫后宫的浴室，这里专供宫女们洗澡用。
LONG );
	set("exits", ([
		"west":__DIR__"gongnufang",
	]));
	set("objects",([
		__DIR__"npc/gongnu":3,
	]));

	setup();
	replace_program(ROOM);
}

