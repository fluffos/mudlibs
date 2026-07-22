// yuxudong.c 玉虚洞 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "玉虚洞");
	set("long", @LONG
眼前是一个半天然，半人工的山洞，四周点着几盏长命灯，正中放着一张桌子，上
面放这几本书。地上零乱的放着七个供人打坐用的蒲团。如果仔细的观察一下，仿
佛感到洞中的摆设藏着什么玄机。
LONG
	);
       
	set("exits", ([
		"out" : __DIR__"yadi",
	    ]));
	set("objects",([
	     __DIR__"npc/chongyang":1,
	     ]));
	setup();
	replace_program(ROOM);
}



