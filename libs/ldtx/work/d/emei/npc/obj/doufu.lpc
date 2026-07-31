// doufu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("豆腐", ({"doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块水灵灵的大豆腐。\n");
		set("unit", "块");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
