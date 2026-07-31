// dumpling.c 包子

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;   
 
void create()
{
	set_name(RED"大枣"NOR, ({"dazao", "zao"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗熟透的大枣。\n");
		set("unit", "颗");
		set("value", 10);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
