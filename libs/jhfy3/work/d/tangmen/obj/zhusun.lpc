// zhusun.c 翡翠竹荪

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("翡翠竹荪", ({"zhusun", "zhu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘爽口的竹海特产-竹荪。\n");
		set("unit", "盘");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
