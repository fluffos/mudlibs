// songbing.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("松饼", ({ "songbing", "bing","song","muffee" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盘上好的松饼。\n");
		set("unit", "盘");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
