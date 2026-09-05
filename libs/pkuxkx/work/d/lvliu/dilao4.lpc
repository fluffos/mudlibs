#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;

void create()
{
	set("short", HIR"五行牢狱·火牢"NOR);
	set("long", HIR"一间着火的地牢。四周堆满了各种引火之物，只一会儿功夫火焰就
已经弥漫至整间牢狱，一眼望去到处全都是火！高温炙烤得你的发尖都
蜷曲了起来，浑身皮肤上也全是满满的灼痛感。不想变成烤猪的话，就
赶紧想办法出去吧！\n"NOR);
	set("exits", ([
	  "east" : __DIR__"path4",
	]));
	set("item_desc", ([
		"east" : "前面黑乎乎的，啥也看不见。\n",
	]));
	set("no_sleep_room",1);
	setup();
}

void init()
{
	object me = this_player();
	object npc, here = this_object();

	if (!objectp(me) || !userp(me)) return;
	
	if (!here->query("fire"))
	{
		here->set("fire", 1);
		call_out("do_fire", 2);
	}

	npc = present("jiguan ren", here);
	if (!objectp(npc) || userp(npc))
	{
		npc=new(__DIR__"npc/jiguanren4");
		if (objectp(npc))
		{
			npc->move(here);
			message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
		}
		return;
	}
	message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
}

void do_fire()
{
	int count;
	object ob=this_object();
	object *allob = all_inventory(ob);
	count = 0;
	for (int i=0; i<sizeof(allob); i++)
	{
		if (!objectp(allob[i])) continue;
		if (!allob[i]->is_character()) continue;
		if (allob[i]->query("race")=="机关人")
		{
			message_vision(HIR"火焰烧灼着$N"HIR"，各个关节处发出了一阵咔咔的声响。\n"NOR, allob[i]);
			allob[i]->receive_wound("qi", allob[i]->query("max_qi")/20, "烧伤");
		}
		if (!userp(allob[i])) continue;
		count++;
		if (!wizardp(allob[i])) 
		{
			message_vision(HIR"火焰烧到了$N"HIR"的肌肤，滋滋冒出了一阵青烟，$N"HIR"痛得惨叫了一声。\n"NOR, allob[i]);
			allob[i]->receive_wound("qi", allob[i]->query("max_qi")/20, "烧伤");
			COMBAT_D->report_status(allob[i]);
		}
	}
	if (count>0)
		call_out("do_fire", 2);
	else
		ob->delete("fire");
}

int valid_leave(object me, string dir)
{
    if ( objectp(present("jiguan ren", environment(me))))
        return notify_fail("机关人巨大的身躯挡住了出口，在把它解决掉之前你根本出不去。\n");
    return ::valid_leave(me, dir);
}

