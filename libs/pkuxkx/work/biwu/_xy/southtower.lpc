// Room: /clone/misc/southtower.c
// create: by zine Aug 21 2010
inherit "/biwu/biwuroom1";
#include <ansi.h>

void create()
{
	set("short", "文德门城楼");
	set("long", @LONG
你来到了城楼之上，极目远眺，城内形势一览无余(lan)。东面是一座狼烟烽
火台，飘扬着大宋的旗帜，但是被一扇巨大的铁门(men)堵住了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"down" : __DIR__"innercitys",
	]));
	set("item_desc", ([
		"men" : "一扇巨大的铁门，怕不止千斤重，你可以试着(tui)开它。\n", 
	]));
	set("no_clean_up", 0);
	set("default_gate_hp",3);
	set("gate_hp",3);
	setup();
}

void init()
{
	add_action("do_push", ({ "push", "tui"}));
	add_action("do_lan", "lan");
	::init();
}

int check(object me)
{
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
	else
		{
			message_vision("$N使出全身力气，奋力推向铁门。\n", me);
			me->set_temp("xiangyang/pushed", 1);
				if(query("gate_hp") - 1 <= 0)
					{
						message_vision(HIG"$N大喝一声，终于把铁门推开。\n"NOR, me);
						me->add_busy(random(2));
						set_temp("open",1);
						set("exits/east", __DIR__"zhongxuanlou");
					}
				else
					{
						add("gate_hp",-1);
						me->add_busy(1+random(2));
						message_vision("门被$N推开一条小缝。\n",me);
					}	
				return 1;
		}
}

#include "tower.h"