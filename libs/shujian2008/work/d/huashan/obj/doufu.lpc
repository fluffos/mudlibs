// ITEM: /d/huashan/obj/doufu.c
// Date: Look 99/03/25

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("麻辣豆腐", ({"mala doufu", "doufu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘清香可口的麻辣豆腐。\n");
		set("unit", "盘");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
