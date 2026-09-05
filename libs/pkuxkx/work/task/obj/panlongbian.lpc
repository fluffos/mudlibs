//taskob
//by lordstar
//2017/8/30
#include <weapon.h>
#include <ansi.h>
#include "task_obj.h"

inherit WHIP;

void create()
{
    set_name("盘龙软鞭",({"panlong bian"}));
	set_weight(5000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","han baoju");
		set("task_owner_cname","韩宝驹");
		set("reward_point",1);
		set("unit","柄");
		set("no_sell",1);
        set("no_beg",1);
	}
	init_whip(100);
	setup();
	
}