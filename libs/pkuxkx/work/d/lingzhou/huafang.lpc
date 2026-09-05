// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "花房");
	set("long", @LONG
这里是西夏国皇宫的花房，这里培育了很多珍贵的品种。
LONG
);
	set("exits", ([
		"south":__DIR__"weishifang",
		"north":__DIR__"yushanfang",
	]));
	set("objects",([
		__DIR__"npc/gongnu":2
	]));
	setup();
	replace_program(ROOM);
}

