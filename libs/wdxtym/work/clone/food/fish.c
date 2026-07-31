// fish.c ¿¾Óã

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("¿¾Óã", ({"kao yu", "yu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÌõÏãÅçÅçµÄ¿¾Óã¡£\n");
		set("unit", "Ìõ");
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
