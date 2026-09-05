#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("肉", ({"rou"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		
		set("food_remaining", 3);
             set("food_supply", 10);
	}
}
