// dumpling.c 包子  

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"香蕉"NOR, ({"xiangjiao", "xiang","jiao"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一串黄橙橙的香蕉。\n");
		set("unit", "串");
		set("value", 120);
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}
