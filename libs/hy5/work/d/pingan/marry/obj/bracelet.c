//bracelet.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
    set_name( HIG "翡翠手镯" NOR, ({ "bracelet" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "一只精致的翡翠雕花手镯\n");
        set("unit", "只");

        set("value", 100000);


        set("material", "jade");
                set("armor_prop/armor", 0);
        set("armor_prop/personality", 10);
        set("wear_msg", "$N轻轻地将一只$n套在了手腕上。\n");
        set("remove_msg", "$N轻轻地把一把$n从腕上除了下来。\n");
        set("no_sell",1);
        set("female_only", 1);

        }
        setup();
}

