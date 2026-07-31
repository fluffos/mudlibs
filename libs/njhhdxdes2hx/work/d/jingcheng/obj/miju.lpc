// dumpling.c 包子 

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"蜜桔"NOR, ({"miju", "ju"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个熟透的蜜桔。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
