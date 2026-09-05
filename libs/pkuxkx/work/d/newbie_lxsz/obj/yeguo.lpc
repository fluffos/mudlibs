// D:\xkx\d\liuxiu-shanzhuang\obj\yeguo.c野果
// labaz 2012/10/20

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

int value();

void create()
{
	set_name(HIM"野果"NOR, ({"ye guo","guo",}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一枚不知从哪掉下的野果，可以用来裹腹。\n");
		set("unit", "枚");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
}

int value()
{
	return 0;
}

