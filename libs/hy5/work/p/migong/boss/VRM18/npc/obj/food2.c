// dumpling.c 包子
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"面包"NOR, ({"mian bao", "mianbao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块面包。\n");
		set("unit", "块");
		set("value", 500);
		set("food_remaining", 6);
		set("food_supply", 60);
	}
}
