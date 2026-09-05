// Room: /clone/misc/northgate.c
// Date: by jason(尔好啊) Tue Nov 17 15:39:52 2009
// edit by zine Aug 21 2010

inherit "/biwu/biwuroom2";
#include <ansi.h>

void create()
{
	set("short", "拱宸门");
	set("long", @LONG
这里是襄阳的北门，越过汉江，北眺故国，汉家江山让人不胜唏嘘。似乎这
里有个瓮城，黑洞洞的你却看不清楚。
LONG
	);
	set("exits", ([
		"south" : __DIR__"northstreet",
		"enter" : __DIR__"innercityn",
	]));
	set("no_clean_up", 0);
	setup();
}

#include "gate.h"