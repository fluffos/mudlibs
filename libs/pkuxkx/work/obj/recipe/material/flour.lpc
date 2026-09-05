inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("面粉", ({ "wheat flour", "flour", "mian", "fen" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一小袋小麦磨的面粉，可以用来做各种食品。\n");
		set("unit", "袋");
    set("value", 20);
//		set("material",  "bone");
	}

	setup();
}

