inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("糙米", ({ "brown rice", "rice", "mi", }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一小袋还未去壳的糙米，可以用来做各种食品。\n");
		set("unit", "袋");
    set("value", 20);
//		set("material",  "bone");
	}

	setup();
}

