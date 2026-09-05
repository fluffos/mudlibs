//taskob
//by lordstar
//2017/8/30
#include <weapon.h>
#include <ansi.h>
#include "task_obj.h"

inherit STAFF;

void create()
{
    set_name("纯钢扁担",({"bian dan"}));
	set_weight(5000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","nan xiren");
		set("task_owner_cname","南希仁");
		set("reward_point",1);
		set("unit","柄");
		set("no_sell",1);
        set("no_beg",1);
	}
	init_staff(100);
	setup();
	
}