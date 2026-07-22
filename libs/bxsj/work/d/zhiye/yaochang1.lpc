// 药厂
// yaochang1.c
// augx@sj 2/28/2002

// Modified by mxzhao 2004/03/06 

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIG"制药作坊"NOR);
	set("long",
"这是间简陋的小屋子，屋子里面最引人注目的是那口终日不息的熬药锅
。这个作坊一般不生产成药，而只是收购采药人采回来的药材原料，加工成
可以用来配药的药材原料。
"); 

/*
	set("objects",([
		__DIR__"npc/yaochang-zhu" : 1,
		__DIR__"obj/yaoguo" : 1,
	]));
*/	
	set("exits",([
		"west" : "/d/chengdu/beidajie2",
	]));
	
	set("indoors", "成都城");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
