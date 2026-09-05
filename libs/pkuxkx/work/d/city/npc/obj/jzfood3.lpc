//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIM"浔阳鱼片"NOR, ({"xunyang yupian","yupian"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一盘浔阳鱼片，让人垂涎欲滴。\n");
            set("unit", "盘");
            set("value", 100);
            set("food_remaining", 4);
            set("food_supply", 70);
    }
}

