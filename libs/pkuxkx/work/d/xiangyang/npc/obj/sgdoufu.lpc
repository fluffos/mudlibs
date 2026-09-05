#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"沙锅豆腐"NOR, ({"shaguo doufu", "doufu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一锅豆腐汤,上面还漂着碧绿的香菜。\n");
		set("unit", "只");
             set("value", 70);
		set("food_remaining", 1);
             set("food_supply", 40);
	}
}
