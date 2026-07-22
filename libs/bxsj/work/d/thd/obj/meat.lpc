// meat.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("猪肉", ({"rou", "meat"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一块红烧的猪肉，还冒着热气呢。\n");
		set("unit", "块");
		set("value", 40);
		set("food_remaining", 2);
		set("food_supply", 25);
	}
}
