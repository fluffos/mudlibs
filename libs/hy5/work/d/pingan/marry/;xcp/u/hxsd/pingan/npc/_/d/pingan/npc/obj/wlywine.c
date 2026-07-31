// wlywine.c

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIW "ŒÂ¡∏“∫" NOR, ({ "wly","wine" }) );
        set_weight(10);
        if( clonep() )
             set_default_object(__FILE__);
        else {
        set("long", "“ª±≠ŒÂ¡∏“∫°£\n");
                set("unit", "±≠");
                set("value", 0);
                set("max_liquid", 20);
        }
        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "alcohol",
                "name": "ŒÂ¡∏“∫",
                "remaining": 20,
                "drunk_apply": 5,
        ]) );
}
