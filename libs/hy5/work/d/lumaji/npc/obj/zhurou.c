// zhurou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Ò°ÖíÈâ", ({ "zhu rou", "rou" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÒ»¿é¿¾ÊìµÄÒ°ÖíÈâ¡£\n");
		set("unit", "¿é");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}