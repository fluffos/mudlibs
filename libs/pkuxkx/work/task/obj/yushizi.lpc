//taskob
//Made by jason@pkuxkx
//2001.1.3

#include <ansi.h>
#include "task_obj.h"

inherit ITEM;

void create()
{
        set_name("玉石子",({"yu shizi"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","huang yaoshi");
		set("task_owner_cname","黄药师");
		set("reward_point",7);
		set("unit","颗");
		set("no_sell",1);
                set("no_beg",1);
//		set("value",1000);
	}
	setup();
	
}
