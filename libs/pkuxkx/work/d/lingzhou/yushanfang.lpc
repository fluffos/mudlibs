// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "御膳房");
	set("long", @LONG
这里是西夏国皇宫的御膳房，各种山珍海味都在这里加工。
LONG
);
	set("exits", ([
		"south":__DIR__"huafang",
		"north":__DIR__"qinfang",
	]));
	set("objects",([
		__DIR__"npc/gongnu":2
	]));
	setup();
	replace_program(ROOM);
}

