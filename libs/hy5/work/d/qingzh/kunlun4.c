// kunlun4.c 昆仑山
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "昆仑山 南麓"NOR);
	set("long", @LONG
你来到了昆仑山南麓，这里气候宜人、山清水秀，时当山花烂漫，一派
灿烂景象。
LONG
	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"north" : __DIR__"kunlun5",
		"south" : __DIR__"kunlun3",
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

