#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name(HIR"珊瑚果"NOR, ({ "guozi" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一种深红色的野生果子\n");
                set("unit", "颗");
                set("value", 0);
                set("food_remaining", 5);
                set("food_supply", 100);
        }
}

