// /u/beyond/mr/obj/guiyuan.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(HIY"桂圆"NOR, ({"gui yuan", "guiyuan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟清香可口的桂圆。\n");
		set("unit", "碟");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
