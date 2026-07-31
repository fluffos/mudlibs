// road8.c 青藏高原-山路到成都
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "山路"NOR);
	set("long", @LONG
这里西往青藏高原，东到蜀地。行这一路可谓艰难险阻一样具全，若无
十分之理由而不得以为之，通常无人过往。
LONG
	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"east" : "/d/chengdu/road1",
//		"southwest" : __DIR__"xroad",
		"northwest" : __DIR__"road7",
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
	ioqi = 500 / (int)ob->query("int") + 2;
        if((int)ob->query("qi") < 50) 
                 message("vinson",HIR"你忽然感到呼吸吃力，身体发软，象是高原反应，歇息一会儿再走吧！\n"NOR, ob);
	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));
        ob->receive_damage("qi", ioqi );
}
*/		

