// zhurou.c 野猪肉

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("野猪肉", ({"zhu rou", "tu"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块鲜血淋漓肥的野猪肉。\n");
		set("unit", "块");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 60);
	}
}
