//didao1.c	出梅庄地道
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","地道");
	set("long",@LONG 
这里墙壁上点着一盏油灯，发出淡黄色光芒，置身之所似是个地道。
地道之内异常狭窄，你的脚步声清晰的在四周回荡，另你毛骨悚然。
LONG
	);

	set("exits", ([
		"north" : __DIR__"outdidao2",
		"out"	: __DIR__"neishi",
	]));
    set("no_task", 1);
	setup();

}

