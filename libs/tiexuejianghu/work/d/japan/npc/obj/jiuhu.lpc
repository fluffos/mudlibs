#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(CYN"米酒"NOR, ({ "mi jiu", "jiu" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("long", YEL"这是一把陶瓷酒壶，里面装着"+name()+"。\n"NOR);
                set("unit", "壶");
             set("value", 1000);
                set("max_liquid", 50);
        }

        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "water",
                 "name": "米酒",
                "remaining": 30,
        ]) );
}
