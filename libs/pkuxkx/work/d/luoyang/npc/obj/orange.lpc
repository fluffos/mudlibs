inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(HIY"橙子"NOR, ({"orange", "cheng zi" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个鲜黄的大橙子，沉甸甸的。\n");
                set("unit", "个");
                set("value", 200);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}
