// fish4.c 比目鱼

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIG"比目鱼"NOR, ({ "bimu yu", "yu","fish" }) );
        set_weight(200+random(200));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "一条比目鱼。\n");
		set("value", 150);
                set("food_remaining", 2);
                set("food_supply", 30);
        }
        setup();
}

