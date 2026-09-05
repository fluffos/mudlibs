#pragma save_binary
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
     set_name(RED"可口可乐"NOR, ({"coke"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
       set("long", "一个用来装可乐的瓶子。\n");
         set("unit", "瓶");
            set("value", 0);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
              "name": RED"可口可乐"NOR,
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
