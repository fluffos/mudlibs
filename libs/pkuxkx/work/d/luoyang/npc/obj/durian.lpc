inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(GRN"榴莲"NOR, ({"durian","liu lian"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个沉甸甸的榴莲，发出奇怪的味道。\n");
                set("unit", "个");
                set("value", 400);
                set("food_remaining", 8);
                set("food_supply", 20);
        }
}

