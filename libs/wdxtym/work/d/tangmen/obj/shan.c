// shan.c ºììËÇà÷­

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ºììËÇà÷­", ({"qingshan", "shan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅÌÏãÆøÆË±ÇµÄºììËÇà÷­¡£\n");
		set("unit", "ÅÌ");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
