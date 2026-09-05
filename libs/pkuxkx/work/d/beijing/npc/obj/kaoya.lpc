// kaoya.c 烤鸭

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(MAG"全聚德招牌烤鸭"NOR, ({"kaoya", "ya"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一只肥得流油的北京烤鸭。\n");
                set("unit", "只");
                set("value", 190);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}

