// buddha_staff.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("拐杖", ({ "cane" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根硬木拐杖，因为经年使用而显得光滑。\n");
                set("value", 600);
                set("material", "wood");
                set("wield_msg", "$N拿出一根$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_staff(7);
        setup();
}
