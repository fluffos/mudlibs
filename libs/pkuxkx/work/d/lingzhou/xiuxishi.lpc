// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是西夏国国王白日批阅奏折中间临时休息的地方，有时晚上也留宿这里。
LONG );
	set("exits", ([
		"east":__DIR__"houdian",
	]));
	set("objects",([
		__DIR__"npc/taijian":2,
	]));

	setup();
	replace_program(ROOM);
}

