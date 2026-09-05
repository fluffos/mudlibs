// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "太医院");
	set("long", @LONG
这里是西夏皇宫的太医院，西夏国最有名的医生几乎都集中在这里。
LONG );
	set("exits", ([
		"north":__DIR__"qifang",
		"south":__DIR__"kufang",
	]));
	set("objects",([
		__DIR__"npc/taiyi":2,
	]));

	setup();
	replace_program(ROOM);
}

