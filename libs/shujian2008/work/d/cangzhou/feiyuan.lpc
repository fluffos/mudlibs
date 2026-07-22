// gbfenduo3.c 丐帮大仁分舵(沧州)
// by Looklove@SJ at 2001/10/03

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","废园");
	set("long", @LONG
这是一座荒废的宅院，从前是一户大户人家，如今人走屋空，四周土墙多
已经倒塌，院子里长了很多杂草。几个乞丐随意做在空地当中，围在一起讨论
着什么。这里是丐帮的大仁分舵，沧州附近的丐帮弟子平常都在这里聚齐。
LONG
	);
	set("exits",([
		"west" : __DIR__"beijie3",
		"enter" : __DIR__"tingtang",
	]));
	set("objects", ([
                CLASS_D("gaibang/fang") : 1,
                CLASS_D("gaibang/jian") : 1,
                CLASS_D("gaibang/zfdizi") : 1,
	]));

	setup();
}