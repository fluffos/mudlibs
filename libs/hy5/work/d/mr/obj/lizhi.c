// /u/beyond/mr/obj/lizhi.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(MAG"ÀóÖ¦"NOR, ({"li zhi", "lizhi"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»µú½¿ºì·¼ÏãµÄÀóÖ¦¡£\n");
		set("unit", "µú");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
