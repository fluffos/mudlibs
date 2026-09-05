// xiongzhang.c 熊掌

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("熊掌", ({"xiong zhang", "zhang"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只又肥又大的大熊掌。\n");
		set("unit", "块");
		set("value", 8000);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}