//taskob
//Made by jason@pkuxkx
//2001.4.4

#include <ansi.h>
#include "task_obj.h"

inherit ITEM;

void create()
{
        set_name("破碗",({"po wan"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","poor man");
		set("task_owner_cname","穷汉");
		set("reward_point",7);
		set("unit","个");
		set("no_sell",1);
//		set("value",1000);
                set("no_beg",1);
		
	}
	setup();
	
}
