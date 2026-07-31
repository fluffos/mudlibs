    //by dewbaby

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name(HIW"失去？来过",({"mifan","fan"}));
    set_weight(100);
  if (clonep() )
    set_default_object(__FILE__); 
   else { 
         set("long", "一个小笨蛋:)。\n"); 
         set("unit", "个"); 
        set("value", 900); 
     set("food_remaining", 10); 
       set("food_supply", 25); 
  }
}
