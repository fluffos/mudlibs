// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "琴房");
	set("long", @LONG
这里是西夏国皇宫里的琴房，皇室人员有时在这里弹琴。
LONG
);
	set("exits", ([
		"east":__DIR__"feizi2",
		"south":__DIR__"yushanfang",
                "north":__DIR__"xuetang",
	]));
	set("objects",([
		__DIR__"npc/gongnu":2
	]));
	setup();
	replace_program(ROOM);
}

