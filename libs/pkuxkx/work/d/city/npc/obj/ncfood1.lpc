//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIM"米粉蒸肉"NOR, ({"mifen zhengrou","rou"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一块米粉蒸肉，让人垂涎欲滴。\n");
            set("unit", "块");
            set("value", 90);
            set("food_remaining", 1);
            set("food_supply", 200);
    }
}

