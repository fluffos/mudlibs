//taskob
//Made by jason@pkuxkx
//2001.1.3

#include <ansi.h>
#include <weapon.h>
#include "task_obj.h"

inherit BLADE;

void create()
{
        set_name("断龙刀",({"duanlong dao"}));
	set_weight(4000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","tian boguang");
		set("task_owner_cname","田伯光");
		set("reward_point",1);
		set("unit","柄");
                set("no_beg",1);
		set("no_sell",1);
	//	set("value",1000);
	}
	init_blade(50);
	setup();
	
}
