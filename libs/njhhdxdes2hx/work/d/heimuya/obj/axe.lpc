// hand_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
        set_name("开山斧", ({ "kill axe", "axe" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "steel");
                set("long",
                        "这种斧头的刃长柄短，是专门用来做兵器的斧头，近战具有相当强的\n"
                        "杀伤力。\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的束带间。\n");
                set("weapon_prop/attack", 3);
                set("weapon_prop/defense", -2);
        }
	init_axe(44);
        setup();
}
