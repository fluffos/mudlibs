//didao2.c	出梅庄地道
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","地道");
	set("long",@LONG 
这里墙壁上点着一盏油灯，发出淡黄色光芒，置身之所似是个地道。
地道高度突然缩小，必须弓身而行，越向前行，弯腰越低。空气更加潮
湿，脚下的泥土也隐隐有些湿意，这里仿佛就是西湖之底了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"outdidao1",
		"north"	: __DIR__"outdidao3",
	]));
    set("no_task", 1);
	setup();

}


