// /u/beyond/mr/obj/yingtao-huotui.c 樱桃火腿
// this is made by beyond
// update 1996.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"樱桃火腿"NOR, ({"yingtao huotui", "huotui"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘色若玫瑰，甜嫩可口的樱桃火腿。\n");
                set("unit", "盘");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
