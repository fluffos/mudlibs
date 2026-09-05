//taskob
//Made by jason@pkuxkx
//2001.1.16

#include <ansi.h>
#include <weapon.h>
#include "task_obj.h"

inherit SWORD;

void create()
{
        set_name("淑女剑",({"shunv jian"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","ning zhongze");
		set("task_owner_cname","宁中则");
		set("reward_point",2);
		set("unit","柄");
                set("no_beg",1);
		set("no_sell",1);
//		set("value",1000);
		
	}
	init_sword(100);
	setup();
	
}
