#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIC"沙锅饭"NOR, ({"shaguo fan", "fan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一种别致的小吃,先用沙锅闷好了饭,再浇上鸡块,鸡汤。\n");
		set("unit", "只");
             set("value", 200);
		set("food_remaining", 2);
             set("food_supply", 60);
	}
}
