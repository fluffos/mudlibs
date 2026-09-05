//wofang.c	农家卧房
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","卧房");
	set("long",@LONG 
这是这户农家的卧房，迎面是一张大炕，足够
七、八个人一起睡。看来这户人家孩子一定不少。
炕上一位农家妇女正在专注地绣着花。
LONG
	);
	set("exits", ([
		"north"	: __DIR__"zhengfang",
	]));
	set("objects",([
		__DIR__"npc/woman" : 1,
			]));
	setup();
}

