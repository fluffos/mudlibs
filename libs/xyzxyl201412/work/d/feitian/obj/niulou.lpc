// shou si.寿司

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("牛肉料理", ({"niu lou", "niulou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是东瀛人士最爱吃的牛肉料理。\n");
		set("unit", "块");
		set("value", 140);
		set("food_remaining", 1);
		set("food_supply", 80);
	}
}
