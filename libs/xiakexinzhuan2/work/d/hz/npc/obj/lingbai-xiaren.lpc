// lingbai-xiaren 菱白虾仁
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW"菱白虾仁"NOR, ({"lingbai xiaren", "xiaren"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘色若玫瑰，甜嫩香嫩的菱白虾仁。\n");
set("unit", "盘");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
