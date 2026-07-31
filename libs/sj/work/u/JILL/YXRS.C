#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name(HIR"鱼香肉丝"NOR, ({ "yxrs", "dish" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘名厨烹调的上好大菜。\n");
                set("unit", "盘");
                set("value", 1000);
                set("food_remaining", 5);
                set("food_supply", 50);
                set("material", "food");
        }
        setup();
}
