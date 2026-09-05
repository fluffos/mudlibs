// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "竹林");
	set("long", @LONG
这里是西夏皇宫里的一片竹林。
LONG );
	set("exits", ([
		"south"  : __DIR__"hougong",
		"north":__DIR__"shuyuan",
		"east":__DIR__"gongzhu",
		"west":__DIR__"wangzi",
	]));

	setup();
	replace_program(ROOM);
}

