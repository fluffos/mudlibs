//dadian1.c	东方不败的成德殿
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","成德殿");
	set("long",@LONG 
这里便是成德殿的正殿了。四周愈加金碧辉煌，豪华之处丝毫
不逊于皇帝的金銮殿。殿上高悬「文成武德」四个大字，殿彼端高
设一座，坐着一个长须老者，自然是日月神教的教主。由于相隔甚
远，此人相貌看不清楚。
LONG
	);
	set("exits", ([
		"out"	: __DIR__"changlang2",
		"northwest" : __DIR__"xicedian",
		"northeast" : __DIR__"dongce",
	]));
	set("objects", ([
                __DIR__"npc/shizhe": 4,
		__DIR__"npc/yang"  : 1,
		__DIR__"npc/dongfang" : 1,
        ]));
	set("no_fight",1);
        set("no_task",1);
	setup();
}

void init()
{
	add_action("stop","yun");
	add_action("stop","exert");
	add_action("stop","perform");
	add_action("stop","yong");
}

int stop()
{
	tell_object(this_player(),"这里不许动武！\n");
	return 1;
}
