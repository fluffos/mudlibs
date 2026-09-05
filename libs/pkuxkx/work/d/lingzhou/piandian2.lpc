// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "偏殿");
	set("long", @LONG
这里是西夏国皇宫的偏殿，有时皇帝在这里和大臣讨论问题。
LONG );
	set("exits", ([
		"east":__DIR__"zhengdian",
	]));
	set("objects",([
		__DIR__"npc/taijian":2,
	]));

	setup();
	replace_program(ROOM);
}

