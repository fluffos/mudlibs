
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
         set_name(MAG"紫菜饭团"NOR, ({"zicai fantuan", "fantuan", "food"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
               set("long", "一个用紫菜包裹着香气扑鼻的"+name()+"。\n");
             set("unit", "个");
           set("value", 300);
             set("food_remaining", 4);
            set("food_supply", 40);
        }
}
