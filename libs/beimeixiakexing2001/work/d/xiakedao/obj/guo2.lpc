//Cracked by Roath
// guo2.c 野果
// ssy
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED "野果" NOR, ({"ye guo", "guo"}));
        set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("value", 20);
                set("food_remaining", 2);
                set("food_supply", 25);
        }

        setup();
}



