// fengmi.c ∑‰√€ By csy 98/12
#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;
void create()
{
     set_name(HIC"∑‰√€"NOR, ({"feng mi","mi"}));
     set_weight(25);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "∂—");
     set("long", "∑‰√€…¢∑¢≥ˆ”’»Àµƒœ„Œ∂°£\n");
     set("no_get", 1);
     set("no_drop", 1);
     set("no_give", 1); 
     set("food_remaining", 1);
     set("food_supply", 50); 
     setup();
     }
}

