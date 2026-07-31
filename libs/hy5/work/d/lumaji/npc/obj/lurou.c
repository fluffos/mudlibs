// lurou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Â¹Èâ", ({ "lu rou", "rou" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÒ»¿é¿¾ÊìµÄÂ¹Èâ¡£\n");
		set("unit", "¿é");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}