//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(YEL"爆山鸡"NOR, ({"bao shanji","ji"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一盘刚炒好的野山鸡，让人垂涎欲滴。\n");
            set("unit", "盘");
            set("value", 20);
            set("food_remaining", 5);
            set("food_supply", 110);
    }
}

