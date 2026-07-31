// /u/beyond/mr/obj/putao.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(GRN"ÆÏÌÑ"NOR, ({"pu tao", "putao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»µú±ÌÓñÇåÏãµÄÆÏÌÑ¡£\n");
		set("unit", "µú");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
