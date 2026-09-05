//taskob
//by lordstar
//2017/8/30
#include <weapon.h>
#include <ansi.h>
#include "task_obj.h"

inherit SPEAR;

void create()
{
    set_name("狼筅",({"lang xian"}));
	set_weight(5000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","qi jiguang");
		set("task_owner_cname","戚继光");
		set("reward_point",1);
		set("unit","柄");
		set("no_sell",1);
        set("no_beg",1);
	}
	init_spear(100);
	setup();
	
}