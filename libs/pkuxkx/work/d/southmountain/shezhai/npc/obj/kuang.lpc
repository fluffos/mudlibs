inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("竹筐"NOR, ({"zhu kuang","kuang","basket"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一只竹筐，矿工可以用来放置粗矿。\n");
            set("unit", "只");
            set("value", 50000);
    }
	setup();
}

