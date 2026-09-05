//taskob
//Made by jason@pkuxkx
//2001.1.3
#include <weapon.h>
#include <ansi.h>
#include "task_obj.h"

inherit STAFF;

void create()
{
        set_name("菩提杖",({"puti zhang"}));
	set_weight(5000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","damo laozu");
		set("task_owner_cname","达摩老祖");
		set("reward_point",6);
		set("unit","柄");
		set("no_sell",1);
                set("no_beg",1);
//		set("value",1000);
	}
	init_staff(100);
	setup();
	
}
