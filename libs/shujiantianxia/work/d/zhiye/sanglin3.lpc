// 桑林小道
// sanglin3.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","桑林小路");
	set("long",
"这里是桑林中的一条小道，四周都是看不到尽头的桑树，外人很容易在这
里迷失方向。好在现在官府已经在此竖立了指示牌指明方向，只要按照指示牌
(sign)的指示走就不会迷路。
"); 
        
	set("exits",([
		"northeast"	: __DIR__"sanglin0",
		"east"		: __DIR__"sanglin13",
		"south"		: __DIR__"sanglin13",
		"west"		: __DIR__"sanglin13",
		"north"		: __DIR__"sanglin13",
	]));
	
	set("item_desc",([
		"sign" : "\n",
	]));
	
	set("outdoors", "长安郊外");
	set("signs",6);
	set("incity",1);
	setup();
}

#include "sanglin-xiaolu.h"
