//taskob
//Made by jason@pkuxkx
//2001.1.16

#include <ansi.h>
#include <weapon.h>
#include "task_obj.h"

inherit SWORD;

void create()
{
        set_name("玉女剑",({"yunv jian"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","xiao longnu");
		set("task_owner_cname","小龙女");
		set("reward_point",5);
		set("unit","柄");
                set("no_beg",1);
		set("no_sell",1);
//		set("value",1000);
		
	}
	init_sword(100);
	setup();
	
}
