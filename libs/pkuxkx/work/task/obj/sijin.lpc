//taskob
//Made by jason@pkuxkx
//2001.1.16

#include <ansi.h>
#include "task_obj.h"

inherit ITEM;

void create()
{
        set_name("带血的丝巾",({"si jin"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","lang huitou");
		set("task_owner_cname","浪回头");
		set("reward_point",3);
		set("unit","块");
		set("no_sell",1);
                set("no_beg",1);
//		set("value",1000);
		
	}
	setup();
	
}
