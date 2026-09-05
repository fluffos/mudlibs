//taskob
//by lordstar
//2017/8/30
#include <weapon.h>
#include <ansi.h>
#include "task_obj.h"

inherit STAFF;

void create()
{
    set_name("大杆秤",({"dagan cheng"}));
	set_weight(5000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","quan jinfa");
		set("task_owner_cname","全金发");
		set("reward_point",1);
		set("unit","柄");
		set("no_sell",1);
        set("no_beg",1);
	}
	init_staff(100);
	setup();
	
}