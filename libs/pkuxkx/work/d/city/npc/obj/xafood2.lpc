//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name("羊肉泡馍"NOR, ({"yangrou paomo","paomo"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一碗羊肉泡馍，让人垂涎欲滴。\n");
            set("unit", "碗");
            set("value", 40);
            set("food_remaining", 4);
            set("food_supply", 20);
    }
}

