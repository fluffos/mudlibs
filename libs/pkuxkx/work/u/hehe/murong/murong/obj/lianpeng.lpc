//lianpeng.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("莲蓬", ({"lian peng", "peng"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个莲蓬。\n");
		set("unit", "条");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}

