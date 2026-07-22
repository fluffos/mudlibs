// 山峰2
// gaoshan2.c
// augx@sj 2/27/2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","山崖");
	set("long",
"这是座高山的一个山崖，山崖上长着不少奇花异草，还有很多珍奇的动物
出没。这里是有名的药材产地，常有采药人来此采药。
"); 
        
	set("exits",([
		"northdown" : __DIR__"gaoshan0",
	]));
	
	set("yaocai",5);
	set("outdoors", "成都郊外");
	set("incity",1);
	setup();
}

#include "gaoshan.h"
