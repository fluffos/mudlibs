// fish7.c 梭鱼

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"梭鱼"NOR, ({ "suo yu", "yu","fish" }) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "一条活蹦乱跳的梭鱼。\n");
		set("value", 200);
                set("food_remaining", 5);
                set("food_supply", 30);
        }
        set_weight(100+random(200));
        setup();
}