//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIW"汉中面皮"NOR, ({"hanzhong mianpi","mianpi"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一碗汉中面皮，让人垂涎欲滴。\n");
            set("unit", "碗");
            set("value", 45);
            set("food_remaining", 3);
            set("food_supply", 25);
    }
}

