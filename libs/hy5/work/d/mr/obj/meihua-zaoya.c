// /u/beyond/mr/obj/meihua-zaoya.c 梅花糟鸭
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"梅花糟鸭"NOR, ({"meihua zaoya", "ya"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘甜嫩可口的梅花糟鸭。\n");
                set("unit", "盘");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
