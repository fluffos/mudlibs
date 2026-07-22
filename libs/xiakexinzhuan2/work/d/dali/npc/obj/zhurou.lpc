
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("猪肉", ({"zhu rou", "rou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块鲜血淋漓的猪肉。\n");
		set("unit", "块");
		set("value", 200);
		set("food_remaining", 6);
		set("food_supply", 50);
	}
}
