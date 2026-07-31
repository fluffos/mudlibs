//yellow-rose.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIR "999朵红玫瑰" NOR, ({ "red flower", "rose","flower" }) );
       set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", HIR "999朵娇艳欲滴的红玫瑰。\n" NOR);
                set("unit", "捆");
               set("value", 1000);
                set("material", "plant");
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
                set("female_only", 1);

        }
        setup();
}
