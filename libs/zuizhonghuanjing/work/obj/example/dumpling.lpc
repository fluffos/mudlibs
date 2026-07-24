// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("包子", ({ "dumpling" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一個香噴噴、熱騰騰的大包子。\n");
		set("unit", "個");
		set("value", 15);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
