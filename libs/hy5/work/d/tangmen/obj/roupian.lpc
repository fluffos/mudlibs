// roupian.c 水煮肉片

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("水煮肉片", ({"roupian", "pian"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盆还冒着油泡的水煮肉片，看起来真够辣。\n");
		set("unit", "盆");
		set("value", 150);
		set("food_remaining", 6);
		set("food_supply", 60);
	}
}
