// fish1.c 鳕鱼

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW"鳕鱼"NOR, ({ "xue yu", "yu","fish" }) );
        set_weight(400+random(600));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "一条鳕鱼，嘴里似乎咬着什么东西。\n");
		set("value", 100);
                set("food_remaining", 5);
                set("food_supply", 50);
        }
        setup();
}