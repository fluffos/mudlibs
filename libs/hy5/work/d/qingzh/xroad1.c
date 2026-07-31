// xroad1.c 青藏高原-血刀门之路
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是青藏高原的一处低谷地带，呼吸似乎不太吃力，行人走到这里都感到
轻松了许多。这里天高水深，风光独好，令人心胸开朗，回想这一路劳累在这美
景面前只换得你嫣然一笑。
LONG
	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"southwest" : __DIR__"xroad2",
		"northwest" : "/d/linzhi/linzhie",
//		"north" : __DIR__"road4",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
	
	setup();
//	replace_program(ROOM);
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
		

