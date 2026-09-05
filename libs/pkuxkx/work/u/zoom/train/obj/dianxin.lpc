// dianxin.c 点心

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("包子", ({"baozi", "dumpling"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块精致的点心。\n");
		set("unit", "块");
		set("value", 50);
		set("food_remaining", 3);
             set("food_supply", 30);
	}
}
