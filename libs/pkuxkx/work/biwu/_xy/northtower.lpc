// Room: /clone/misc/northtower.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom1";
#include <ansi.h>

void create()
{
	set("short", "拱宸门城楼");
	set("long", @LONG
你来到了城楼之上，极目远眺，城内形势一览无余(lan)。西面是一座门楼，
飘扬着大宋的旗帜，但是被一扇巨大的铁门(men)堵住了。南面城墙有道缺口，
现在正刮着北风，如果能借力于什么东西，你似乎可以飘(piao)下去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"down" : __DIR__"innercityn",
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
    add_action("do_piao", ({ "piao", "fly"}));
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
					set("exits/west", __DIR__"linhanlou");
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



int do_piao()
{ 
	object me = this_player();
    if(!present("kite", me))
		{
			message_vision(RED"$N全无助力，一头栽了下城去。\n"NOR,me);
			me->move(__DIR__"northgate");
			me->unconcious();
		}
	else 
		{
			message_vision(HIC"$N双手紧握风筝，如天外飞仙般向南飘去。\n"NOR, me);
			me->move(__DIR__"northgate");
		    me->add_busy(2);
			call_out("piao2", 2, me);
		}
	return 1;
}
	
int piao2(object me)
{
	message_vision(HIW"耳边风声划过，$N很帅的梳理了一下头发。\n"NOR, me);
	me->move(__DIR__"northstreet");
	me->add_busy(2);
	call_out("piao3", 2, me);
	return 1;
}

int piao3(object me)
{
	message_vision(YEL"风声越来越急，速度越来越快，$N不由心底有点紧张。\n"NOR, me);
    me->move(__DIR__"northdoor");
	me->add_busy(2);
	call_out("piao4", 2, me);
	return 1;
}

int piao4(object me)
{
	object kite;
	message_vision(HIR"风筝似乎不受控制了，$N吓得闭上了眼睛，妈呀！一股细流从$N双腿间流过。\n"NOR, me);
	if (random(5)>3)
		{
			me->move(__DIR__"backyard");
			message_vision(RED"风筝经不住气流冲击，破了一个大洞，$N噗通一声，一个倒栽葱插入地下。\n"NOR, me);
			me->add("qi",-(random(100)));
			me->add_busy(random(3));
		}
	else if (random(5)>2)
		{
			me->move(__DIR__"cityhall");
			message_vision(BLU"风筝经不住气流冲击，破了一个大洞，$N噗通一声，一个倒栽葱插入地下。\n"NOR, me);
			me->add("qi",-(random(100)));
			me->add_busy(random(3));
		}
	else
		{
			me->move(__DIR__"southdoor");
			message_vision(WHT"风筝经不住气流冲击，破了一个大洞，$N噗通一声，一个倒栽葱插入地下。\n"NOR, me);
			me->add("qi",-(random(100)));
			me->add_busy(random(3));
		}
	kite=present("kite",me);
	if(objectp(kite)) 
	destruct(kite);
	return 1; 
}

#include "tower.h"