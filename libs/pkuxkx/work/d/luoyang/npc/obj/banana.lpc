inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(HIY"香蕉"NOR, ({"banana", "xiang jiao" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一根黄澄澄的香蕉，散发出诱人的香味。\n");
                set("unit", "个");
                set("value", 200);
                set("food_remaining", 2);
                set("food_supply", 15);
        }
}
