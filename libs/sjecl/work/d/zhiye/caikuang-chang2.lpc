// 采矿场山路
// caikuang-chang2.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","山路");
	set("long",
"这是一条陡峭的山路，山雾很重，容易出现幻象，过去有不少矿工就是因
为幻象而走错了路，跌下山崖而死。好在现在官府已经在此竖立了指示牌指明
方向，只要小心的按照指示牌(sign)的指示走就不会有危险。
"); 
        
	set("exits",([
		"northdown"	: __DIR__"caikuang-chang10",
		"east"		: __DIR__"caikuang-chang12",
		"south"		: __DIR__"caikuang-chang12",
		"west"		: __DIR__"caikuang-chang12",
		"north"		: __DIR__"caikuang-chang12",
	]));
	
	set("item_desc",([
		"sign" : "\n",
	]));
	
	set("outdoors", "扬州郊外");
	set("signs",6);	
	set("incity",1);
	setup();
}

#include "caikuang-shanlu.h"
