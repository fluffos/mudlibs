//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIW"豆腐酿"NOR, ({"doufu niang","doufu","niang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一盘畲族传统的豆腐酿。\n");
            set("unit", "盘");
            set("value", 200);
            set("food_remaining", 2);
            set("food_supply", 50);
    }
}

