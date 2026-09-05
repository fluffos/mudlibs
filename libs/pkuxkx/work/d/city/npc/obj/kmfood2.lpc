//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(WHT"锅贴乌鱼"NOR, ({"guotie wuyu","wuyu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一盘锅贴乌鱼，让人垂涎欲滴。\n");
            set("unit", "盘");
            set("value", 220);
            set("food_remaining", 2);
            set("food_supply", 80);
    }
}

