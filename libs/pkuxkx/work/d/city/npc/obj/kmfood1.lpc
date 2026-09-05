//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIG"青椒松茸"NOR, ({"qingjiao songrong","songrong"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一盘青椒松茸，让人垂涎欲滴。\n");
            set("unit", "盘");
            set("value", 190);
            set("food_remaining", 3);
            set("food_supply", 50);
    }
}

