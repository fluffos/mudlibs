// niqiu.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("¸ÉìÔÄàöú", ({"niqiu","food"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅÌÏãÅçÅçµÄ¸ÉìÔÄàöú¡£\n");
		set("unit", "ÅÌ");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 15);
	}
}
