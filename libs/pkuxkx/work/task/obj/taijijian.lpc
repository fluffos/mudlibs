//taskob
//Made by jason@pkuxkx
//2001.1.3
#include <weapon.h>

inherit SWORD;
#include "task_obj.h"

void create()
{
        set_name("太极剑",({"taiji jian"}));
	set_weight(5000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","zhang sanfeng");
		set("task_owner_cname","张三丰");
		set("reward_point",5);
		set("unit","柄");
		set("no_sell",1);
//		set("value",1000);
                set("no_beg",1);
	}
	init_sword(100);
	setup();
	
}
