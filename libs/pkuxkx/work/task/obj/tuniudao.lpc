//taskob
//by lordstar
//2017/8/30
#include <weapon.h>
#include <ansi.h>
#include "task_obj.h"

inherit BLADE;

void create()
{
    set_name("屠牛刀",({"tuniu dao"}));
	set_weight(4000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","zhang asheng");
		set("task_owner_cname","张阿生");
		set("reward_point",1);
		set("unit","柄");
		set("no_sell",1);
        set("no_beg",1);
	}
	init_blade(100);
	setup();
	
}