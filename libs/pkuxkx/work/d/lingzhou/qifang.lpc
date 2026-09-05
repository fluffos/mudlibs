// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "棋房");
	set("long", @LONG
这里是西夏皇宫的棋房，皇帝、皇后、嫔妃、王子、公主有时在这里下棋、聊天。
LONG );
	set("exits", ([
		"north":__DIR__"huayuan",
		"south":__DIR__"taiyiyuan",
		"west":__DIR__"feizi1",
	]));

	setup();
	replace_program(ROOM);
}

