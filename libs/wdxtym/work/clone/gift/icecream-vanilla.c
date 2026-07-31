// icecream-vanilla.c

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW "雪糕" NOR, ({ "vanilla icecream", "vanilla", "icecream" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "一支香草口味的雪糕，清凉可口。"NOR"\n");
		set("value", 1000);
		   set("unit", "支");
		   set("food_remaining", 2);
		   set("food_supply", 100);
	}
	setup();
}

int query_autoload() { return 1; }
