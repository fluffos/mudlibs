//taskob
//by lordstar
//2017/8/30
#include <weapon.h>
#include <ansi.h>
#include "task_obj.h"

inherit SWORD;

void create()
{
    set_name("青钢剑",({"qinggang jian"}));
	set_weight(5000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","feng xifan");
		set("task_owner_cname","冯锡范");
		set("reward_point",3);
		set("unit","柄");
		set("no_sell",1);
        set("no_beg",1);
	}
	init_sword(100);
	setup();
	
}
