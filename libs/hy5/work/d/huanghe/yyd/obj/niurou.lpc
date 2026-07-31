// niurou.c 原笼粉蒸牛肉

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "原笼粉蒸牛肉" NOR, ({"niurou"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一笼热气腾腾，葱肉香气扑鼻，肉质细嫩酥烂的粉蒸牛肉\n");
		set("unit", "笼");
		set("value", 190);
		set("food_remaining", 2);
		set("food_supply", 50);
	}
}