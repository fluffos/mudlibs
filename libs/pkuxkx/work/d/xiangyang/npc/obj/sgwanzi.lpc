#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIR"沙锅丸子"NOR, ({"shaguo wanzi", "wanzi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一锅鲜美的汤,里面是鱼肉做的丸子。\n");
		set("unit", "只");
             set("value", 120);
		set("food_remaining", 3);
             set("food_supply", 50);
	}
}
