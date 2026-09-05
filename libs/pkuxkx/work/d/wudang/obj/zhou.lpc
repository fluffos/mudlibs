// zhou.c 糯米粥

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("糯米粥", ({"nuomi zhou", "zhou"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗稠稠的糯米粥，还冒着热气呢，快趁热吃了吧。\n");
		set("unit", "碗");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
