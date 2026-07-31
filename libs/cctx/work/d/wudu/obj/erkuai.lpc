//erkuai.c 洱块 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("洱块", ({"erkuai"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块又糯又香的洱块。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
