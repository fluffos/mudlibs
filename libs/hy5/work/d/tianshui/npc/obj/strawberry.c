// strawberry.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("草莓", ({ "strawberry" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个红红的大草莓。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 4);
		set("food_supply", 10);
	}
	setup();
}