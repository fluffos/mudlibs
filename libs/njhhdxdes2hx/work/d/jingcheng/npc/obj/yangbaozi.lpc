#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
       set_name("羊肉包子", ({"yangrou baozi", "baozi" }));
       set_weight(60);
        if(clonep() )
               set_default_object(__FILE__);
         else {
               set("long"," 一个羊肉做的包子. \n");
                set("unit","个");
              set("value",150);
               set("food_remaining",2);
               set("food_supply",25);
       }
}
