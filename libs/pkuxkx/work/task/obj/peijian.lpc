//taskob
//Made by jason@pkuxkx
//2001.1.3

#include <ansi.h>
#include <weapon.h>
#include "task_obj.h"

inherit SWORD;

void create()
{
        set_name("佩剑",({"pei jian"}));
	set_weight(4000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","linghu chong");
		set("task_owner_cname","令狐冲");
		set("reward_point",2);
		set("unit","柄");
                set("no_beg",1);
		set("no_sell",1);
//		set("value",1000);
	}
	init_sword(50);
	setup();
	
}
