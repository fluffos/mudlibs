
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
         set_name(WHT"生鱼片"NOR, ({"sheng yupian", "yupian", "fish"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
               set("long", "一盘鲜嫩味美的"+name()+"。\n");
                set("unit", "盘");
                set("value", 3000);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}
