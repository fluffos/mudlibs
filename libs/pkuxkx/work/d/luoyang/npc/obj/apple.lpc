inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
        set_name(HIR"苹果"NOR, ({"apple", "ping guo" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个皮儿红扑扑的，鲜亮鲜亮的苹果。\n");
                set("unit", "个");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 10);
        }
}
