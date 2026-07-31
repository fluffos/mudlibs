//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"左家大院"NOR);
	set("long", @LONG
你走进大院，迎面是一个屏风，屏风上画着一些美丽的园景，据说是当年
西施用过的东东。屏风后面是假山，山后有个水池，水池中有个喷泉，水花
四散，十分好看。园子东南边是一些花草，一个园丁正在工作。
LONG
	);
	set("exits", ([
		"east" : __DIR__"zuojia",
		"southwest" : __DIR__"zuojia3",
]));                                      
	set("objects", ([
		__DIR__"npc/yuanding" : 1,
]));
	setup();
	replace_program(ROOM);
}
