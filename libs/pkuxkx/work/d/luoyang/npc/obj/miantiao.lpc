inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(HIW"浆面条"NOR, ({ "jiang miantiao", "miantiao" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一盘浆面条，洛阳的名吃。\n");
                set("unit", "盘");
                set("value", 1000);
                set("food_remaining", 10);
                set("food_supply", 10);
                set("material", "meat");
        }
        setup();
}
