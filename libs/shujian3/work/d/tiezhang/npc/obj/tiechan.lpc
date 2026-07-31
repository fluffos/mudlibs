// tiechui.c

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name("铁铲",({ "tie chan", "chan", "tiechan", "staff"}) );
         set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "bamboo");
                set("long", "这是一把大铁铲。\n");
                set("wield_msg", "$N拿出一个$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_staff(20);
        setup();
}

