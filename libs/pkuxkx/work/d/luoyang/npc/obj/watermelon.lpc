inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(HIG"西瓜"NOR, ({"watermelon", "xi gua" }));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个绿油油的大西瓜，看起来很好吃的样子。\n");
                set("unit", "个");
                set("value", 200);
                set("food_remaining", 10);
                set("food_supply", 10);
        }
}
