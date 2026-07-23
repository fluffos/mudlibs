#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(MAG"香蕉"NOR, ({"xiang jiao", "xiangjiao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟香蕉，香气浓郁，你真想立刻吃上一个。\n");
		set("unit", "碟");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
