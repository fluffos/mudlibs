#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(MAG"菠萝"NOR, ({"bo luo", "boluo"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟削好了的菠萝，你的口水都要流下来了。\n");
		set("unit", "碟");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
