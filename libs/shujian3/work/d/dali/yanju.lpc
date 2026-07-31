inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"作坊"NOR);
	set("long", @long
这是间简陋的小屋子，屋子里面最引人注目的是那口终日不息的熬药锅。
这个作坊一般不生产成药，而只是收购采药人采回来的药材原料，加工成可以
用来配药的药材原料。
long	);

	set("exits", ([
		"west" : __DIR__"beijie5",
	]));

//	set("objects", ([
//		"/d/zhiye/obj/yaoguo" : 1,
//		"/d/zhiye/npc/yaochang-zhu" : 1,
//	]));
	set("no_fight", 1);
	set("no_zhiye", 1);
	set("incity", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/yanju",1);
}
