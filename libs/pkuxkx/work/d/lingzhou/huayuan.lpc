// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "花园");
	set("long", @LONG
这里是西夏皇宫的花园，里边开满了各种各样五颜六色的鲜花，花丛中有几个宫女在采花。
LONG );
	set("exits", ([
		"south":__DIR__"qifang",
		"west":__DIR__"gongzhu",
	]));
	set("objects",([
		__DIR__"npc/gongnu":3,
	]));

	setup();
	replace_program(ROOM);
}

