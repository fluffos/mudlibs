
// mudao./d/mingjiao/npc/obj/mudao.c
#include <weapon.h>
#include <command.h>
inherit BLADE;
void create()
{
        set_name("木刀", ({ "mu dao", "dao", "blade" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 250);
                set("material", "iron");
    set("long", "这是一柄木制的短刀，是平常练武用的刀，以免伤人。\n");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插回腰间。\n");
             
        }
        init_blade(5);
        setup();
}
