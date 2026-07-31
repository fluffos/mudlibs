// kunlun1.c 昆仑山
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "青山翠谷"NOR);
	set("long", @LONG
你左看右顾，处处是参天绿树遮阳避日，到处可闻鸟儿自在的歌唱，各种可
爱的小生灵在你面前蹦跳，并不怕你，看了这些不禁神伤--想这人间只知有名利
二人，尽累于争名逐利... 却不识有这般和谐相处之道！唉，只希望数世之后人
还能保存这些森林，留下这一方净土！
LONG
	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"northeast" : __DIR__"kunlun2",
		"south" : __DIR__"kunlun",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
	
	setup();
	replace_program(ROOM);
}

/*	
void init()
{
	object ob;
	int ioqi;
	
	ob = this_player();
	ioqi = 300 / (int)ob->query("int") + 3;
        if((int)ob->query("qi") < 50) 
                 message("vinson",HIR"你忽然感到呼吸吃力，身体发软，象是高原反应，歇息一会儿再走吧！\n"NOR, ob);
	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));
        ob->receive_damage("qi", ioqi );
}
*/		

