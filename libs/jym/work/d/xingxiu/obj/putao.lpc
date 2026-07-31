//Cracked by Roath
// maco

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("葡萄", ({"grape", "putao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一串吐鲁番出产的葡萄，颗颗鲜绿晶亮，甘甜芳香。\n");
		set("unit", "串");
		set("value", 20);
		set("food_remaining", 6);
		set("food_supply", 10);
		set("eat_msg","$N吃下了几颗葡萄。");
	}
}
