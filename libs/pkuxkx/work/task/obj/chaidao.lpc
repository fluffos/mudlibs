//taskob
//Made by jason@pkuxkx
//2001.4.4

#include <ansi.h>
#include "task_obj.h"

inherit ITEM;

void create()
{
        set_name("柴刀",({"chai dao"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
                set("task_owner","kan chairen");
                 set("task_owner_cname","砍柴人");
		set("reward_point",5);
		set("unit","把");
                set("no_beg",1);
		set("no_sell",1);
//		set("value",1000);
		
	}
	setup();
	
}
