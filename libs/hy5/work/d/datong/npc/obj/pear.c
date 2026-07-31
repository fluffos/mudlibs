// pear.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鸭梨", ({ "pear" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个金黄色的大鸭梨。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
	setup();
}