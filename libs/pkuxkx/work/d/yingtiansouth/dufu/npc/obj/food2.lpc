//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIW"素干丝"NOR, ({"su gansi","gansi"}));
	set_weight(700);
	set("meng_food",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一小碟"+query("name")+"，让人垂涎欲滴。\n");
            set("unit", "盘");
            set("value", 5);
            set("food_remaining", 1);
            set("food_supply", 35);
    }
}

