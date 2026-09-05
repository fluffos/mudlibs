// wanzi.c 丸子

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(HIM"四喜丸子"NOR, ({"sixi wanzi", "wanzi"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗香气逼人的丸子，看得你流口水......。\n");
		set("unit", "碗");
		set("value", 600);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
