// fengmi.c 蜂蜜
// By River 98/09
#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;
void create()
{
     set_name(HIC"蜂蜜"NOR, ({"feng mi","mi"}));
     set_weight(25);
     if (clonep())
            set_default_object(__FILE__);
     else {
            set("unit", "堆");
            set("long", "蜂蜜散发出诱人的香味。\n");
            set("no_get", 1);
            set("no_drop", 1);
            set("no_give", 1); 
            set("food_remaining", 1);
            set("food_supply", 50); 
     }
     setup();
}
