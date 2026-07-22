
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("板豆腐", ({"ban doufu", "doufu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块普通的家常豆腐，散发着清香。\n");
		set("unit", "块");
		set("value", 70);
		set("food_remaining", 1);
		set("food_supply", 80);
	}
}
