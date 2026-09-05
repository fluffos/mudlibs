#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(BNK"潜能"NOR, ({ "potential" }));
     set_weight(0);
                set("food_remaining", 2);
             set("food_supply", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "万点");
                set("value", 1);
                set("material", "paper");
                set("long",
                        HIY"这就是mud里人人都想要的"+BNK"潜能!\n"NOR);
            }
}
