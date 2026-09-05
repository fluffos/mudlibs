// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "车马房");
	set("long", @LONG
这里是西夏皇宫的车马房，里边停放着各种车马及皇宫人员出宫所需的物品。
LONG );
	set("exits", ([
		"north":__DIR__"kufang",
		"west":__DIR__"gongsquare",
	]));
	set("objects",([
		__DIR__"npc/taijian":2,
	]));

	setup();
	replace_program(ROOM);
}

