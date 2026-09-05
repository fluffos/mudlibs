//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIW"羊肉泡馍"NOR, ({"yangrou paomo","paomo","yangrou"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一碗西北著名的羊肉泡馍。\n");
            set("unit", "碗");
            set("value", 400);
            set("food_remaining", 3);
            set("food_supply", 50);
    }
}

