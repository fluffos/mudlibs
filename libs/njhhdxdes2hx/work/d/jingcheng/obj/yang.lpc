// dumpling.c 包子

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"杨梅"NOR, ({"yangmei", "mei"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗熟透的杨梅。\n");
		set("unit", "颗");
		set("value", 20);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
