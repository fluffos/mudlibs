inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(BLU"菠萝"NOR, ({"pineapple", "bo luo" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "菠萝也叫做“凤梨”，是岭南 四大佳果之一。\n");
                set("unit", "个");
                set("value", 200);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}
