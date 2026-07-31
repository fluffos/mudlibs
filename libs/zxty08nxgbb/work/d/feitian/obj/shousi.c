// shou si.寿司

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("寿司", ({"shou si", "si"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是东瀛人士最爱吃的寿司。\n");
		set("unit", "块");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 80);
	}
}
