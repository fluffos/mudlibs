// icecream-chocolate.c

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(WHT "雪糕" NOR, ({ "chocolate icecream", "chocolate", "icecream" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "一支巧克力口味的雪糕，香甜可口，美中不足是吃了容易发胖。"NOR"\n");
		set("value", 1000);
		set("unit", "支");
		set("food_remaining", 2);
		set("food_supply", 100);
	}
	setup();
}

int query_autoload() { return 1; }
