// zhashanji.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("炸山鸡", ({"zha shanji", "shanji","ji"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只炸得喷喷香的山鸡。\n");
		set("unit", "只");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
