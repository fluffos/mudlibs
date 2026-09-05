//Made By:pingpang
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","归云庄大门");
	set("long",@LONG
这里是归云庄的大门，归云庄是连成一片的宏伟巨宅，此地有两位武士把守。
门前有两幅对联（lian），是江南风格的一派装饰。
LONG);
	set("item_desc",(["lian":RED"最好太湖景,必来归云庄\n"NOR
			]));	
	set("exits",(["enter":__DIR__"shijie",
		      "west":__DIR__"taihubian"
		    ]));
	set("objects",([__DIR__"npc/wushi":2,]));
	setup();
}

void init()
{
	object *all;
	all=all_inventory(this_object());
	for (int i=0;i<sizeof(all);i++)
	{
		if (all[i]->query_temp("shediaoquest/guiyun/step")==5)
		{
			all[i]->set_temp("shediaoquest/guiyun/step",6);
			tell_object(all[i],HIC+"来到庄前。你不由惊叹这渔人所居竟是这般宏伟的巨宅。\n"+NOR);
		}
	}
	return;
}