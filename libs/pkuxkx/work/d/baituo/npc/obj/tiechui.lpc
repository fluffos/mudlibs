// /d/baituo/npc/obj/dachui.c
// --by bibi--
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("大铁锤", ({ "da tiechui", "tiechui", "chui","hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把又大又重的大铁锤，必是膂力过人之人才能使用。\n");
                set("value", 1000);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N慢慢放下手中的$n。\n");
        }

        init_hammer(20);
        setup();
}
