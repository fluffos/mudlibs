// turou.c ºìÉÕ¹·Èâ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ºìÉÕ¹·Èâ", ({"gou rou", "gou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÍëÏãÅçÅçµÄºìÉÕ¹·Èâ\n");
		set("unit", "Íë");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}

