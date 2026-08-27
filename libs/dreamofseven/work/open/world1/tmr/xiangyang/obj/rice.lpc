// rice.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIR"高粱米飯"NOR, ({ "rice", "mi fan" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗香噴噴的高粱米飯。\n");
		set("unit", "碗");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 10);
		set("material", "rice");
	}
	setup();
}

