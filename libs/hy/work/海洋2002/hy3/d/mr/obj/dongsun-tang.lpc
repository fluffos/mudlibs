// /u/beyond/mr/obj/dongsun-tang 菏叶冬笋汤
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW"菏叶冬笋汤"NOR, ({"dongsun tang", "tang"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘色若玫瑰，甜嫩可口的菏叶冬笋汤。\n");
                set("unit", "盘");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
