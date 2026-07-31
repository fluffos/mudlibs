// yangrou.c 羊肉

#include <weapon.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("羊肉", ({ "yang rou", "rou" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块香喷喷的羊肉。\n");
		set("unit", "块");
		set("value", 30);
		set("food_remaining", 5);
		set("food_supply", 50);
		}
	setup();
}

