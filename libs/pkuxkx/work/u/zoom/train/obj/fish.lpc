
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鱼", ({"fish", "yu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一条小鱼。\n");
		set("unit", "条");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}

