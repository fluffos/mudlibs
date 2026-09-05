// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "库房");
	set("long", @LONG
这里是西夏皇宫的库房，里边摆放着大量皇宫中所需的物品。
LONG );
	set("exits", ([
		"north":__DIR__"taiyiyuan",
		"south":__DIR__"chemafang",
	]));
	set("objects",([
		__DIR__"npc/taijian":2,
	]));

	setup();
	replace_program(ROOM);
}

