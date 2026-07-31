#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
       set_name("大米",({"da mi","mi"}));
       set_weight(1000);
       if( clonep() )
              set_default_object(__FILE__);
        else {
              set("long","一袋大米.\n");
              set("unit","袋");
                set("value",1000);
                set("food_remaining",4);
                set("food_supply",70);
       }
}
