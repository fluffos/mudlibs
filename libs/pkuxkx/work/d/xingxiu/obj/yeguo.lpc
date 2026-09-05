// 野果
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("野果", ({"fruit", "guo"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只不知名的野果。\n");
		set("unit", "只");
        set("value", 0);
		set("food_remaining", 3);
        set("food_supply", 30);
	}
}
