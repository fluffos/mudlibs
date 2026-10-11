// road.c 桃源大道
// Design By BMW add from 2000.3.26

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","桃源大道");
	set("long",@LONG
这是桃源山庄通往各位英雄隐居之地，不过暂时还不知道是哪位英雄
在这里隐居的英雄是谁！
LONG
);
	set("exits",([
		"south"    :__DIR__"road_6",
	]));
	setup();
	replace_program(ROOM);
}
