// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "御书院");
	set("long", @LONG
这里是西夏皇宫的御书院，这里密密麻麻排满了书架，上面摆放着各种各样的图书。
LONG );
	set("exits", ([
		"south"  : __DIR__"zhulin1",
		"west":__DIR__"taijianfang",
		"east":__DIR__"gongnufang",
	]));
	set("objects",([
		__DIR__"npc/taijian":2,
	]));

	setup();
	replace_program(ROOM);
}

