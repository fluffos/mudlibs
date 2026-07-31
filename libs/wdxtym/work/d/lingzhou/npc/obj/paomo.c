// food: paomo.c
// Java Sep. 23 1998

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÑòÈâÅİâÉ", ({"yangrou paomo", "yangrou", "paomo"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÍëÏãÅçÅçµÄÑòÈâÅİâÉ¡£\n");
		set("unit", "Íë");
		set("value", 150);
		set("food_remaining", 5);
		set("food_supply", 40);
	}
}

