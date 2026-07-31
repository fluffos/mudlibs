//Cracked by Roath
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BBLK+RED "野果" NOR, ({"fruit","ye guo", "guo"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一颗红色的野果，看起来可以吃。\n"  );
                set("unit", "颗");
                set("value", 20);
                set("food_remaining", 5);
                set("food_supply", 10);
        }
}

