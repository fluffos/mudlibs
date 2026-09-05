inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(MAG"荔枝"NOR, ({"lichee", "li zhi" }));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一串新鲜的荔枝，还有一些绿色的叶子。荔枝享有“岭南果王”和“果中珍品”的美誉，驰名中外。\n");
                set("unit", "个");
                set("value", 300);
                set("food_remaining", 10);
                set("food_supply", 10);
        }
}

