
#include <ansi.h> 

inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name(HIY"蒸鸡"NOR, ({"zheng ji","ji"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一只香喷喷的蒸鸡。\n");
                set("unit", "只");
                set("value", 1000);
                set("food_remaining", 60);
                set("food_supply", 70);
        }
}

