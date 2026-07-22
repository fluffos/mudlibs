#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(MAG"芒果"NOR, ({"mang guo", "manguo"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟黄澄澄的芒果。香气扑鼻。\n");
		set("unit", "碟");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
