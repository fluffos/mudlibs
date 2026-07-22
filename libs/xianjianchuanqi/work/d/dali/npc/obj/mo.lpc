
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("羊肉泡馍", ({"yangrou paomo", "paomo"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的羊肉泡馍。\n");
		set("unit", "碗");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
