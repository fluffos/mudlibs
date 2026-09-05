//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIR"酸汤水饺"NOR, ({"suantang shuijiao","shuijiao"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一盘酸汤水饺，让人垂涎欲滴。\n");
            set("unit", "盘");
            set("value", 50);
            set("food_remaining", 3);
            set("food_supply", 30);
    }
}

