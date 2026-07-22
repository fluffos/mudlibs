// 农田
// nongtian11.c
// augx@sj 10/17/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","农田");
	set("long",
"这是一片还没有种上庄稼的农田，你可以在这里种植(zhongzhi)自己的植
物。农田旁还有一个水塘和肥料池，你可以用来浇水(jiaoshui)和施肥(shife
i)。等你种植的植物成熟了就可以收割(shouge)了。
"); 
        
	set("exits",([
		"out" : __DIR__"nongtian1",
	]));
	
	set("outdoors", "长安郊外");
	set("incity",1);
	set("exam",0);
	setup();
}

#include "nongtian.h"
