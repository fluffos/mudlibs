// /u/beyond/mr/obj/tangyuan.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(HIW"汤圆"NOR, ({"tang yuan", "tangyuan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗小巧白嫩可口的汤圆。\n");
		set("unit", "碗");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
