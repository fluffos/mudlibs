// road3.c 青藏高原
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","青藏高原");
	set("long", @LONG
你正走在青藏高原，这里海拔太高空气稀薄，只一会儿，你就上气不接下气了。
这里人际罕至，方圆百里不见人烟，不只如何才走得出去...
LONG
	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"south" : __DIR__"road4",
		"northeast" : __DIR__"road2",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
	
	setup();
//	replace_program(ROOM);
}

	
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
		

