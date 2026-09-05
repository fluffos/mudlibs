// Room: menggubao.c
// created by Zine 30 Aug 2010

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", YEL"蒙古包"NOR);
	set("long", @LONG
这里是蒙古的一个小部落，往北是一片蒙古包，被一片大草原包围着。
LONG
	);

	set("exits", ([
		"south" : __DIR__"grass",
		"north" : __DIR__"menggubao",
	]));
	set("objects", ([
        	__DIR__"npc/muyangren" : 1,
	]));
	set("outdoors", "menggu_e");
    setup();
}
