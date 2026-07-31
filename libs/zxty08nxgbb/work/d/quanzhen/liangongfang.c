// liangongfang.c 练功房
// by kyd

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是练功房，地下凌乱地放着几个蒲团，几位全真弟子正盘膝坐在上
面打坐。
LONG
	);
	set("exits", ([
		"east" : __DIR__"xilang3",
	]));
	
	set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}
