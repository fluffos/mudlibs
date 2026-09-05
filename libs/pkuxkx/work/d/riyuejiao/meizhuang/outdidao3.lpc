//outdidao3.c	出梅庄地道
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","地道");
	set("long",@LONG 
墙壁上点着一盏油灯，发出淡黄色光芒，置身之所似是个地道。
这里有一扇铁门(gate)，铁门上有个尺许见方的洞孔。里面灯光很
暗，黑乎乎的看不清楚，仿佛是个牢房。
LONG
	);

	set("exits", ([
		"south" : __DIR__"outdidao2",
		"enter" : __DIR__"prison2",
	]));

    set("no_task", 1);
	setup();
}

