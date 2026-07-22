// 农田路
// nongtian2.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","田埂");
	set("long",
"这里是四片农田的交接处，四周的农田看起来都一模一样，很容易迷路。
好在现在官府已经在此竖立了指示牌指明方向，只要按照指示牌(sign)的指示
走就不会迷路。
"); 
        
	set("exits",([
		"northwest"	: __DIR__"nongtian0",
		"east"		: __DIR__"nongtian12",
		"south"		: __DIR__"nongtian12",
		"west"		: __DIR__"nongtian12",
		"north"		: __DIR__"nongtian12",
	]));
	
	set("item_desc",([
		"sign" : "\n",
	]));
	
	set("outdoors", "长安郊外");
	set("signs",6);
	set("incity",1);
	setup();
}

#include "nongtian-lu.h"
