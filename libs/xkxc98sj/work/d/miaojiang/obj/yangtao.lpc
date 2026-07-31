#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(MAG"杨桃"NOR, ({"yan tao", "yangtao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟水灵灵熟透了的杨桃，你的忍不住想拿起一个来吃。\n");
		set("unit", "碟");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
