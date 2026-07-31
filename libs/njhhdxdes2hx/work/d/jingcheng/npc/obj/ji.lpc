// hand_axe.c

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("长戟", ({ "chang ji", "ji" }) );
        set_weight(8500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "steel");
                set("long","一把长戟,冒着寒气令人不寒而栗!\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背後的长囊间。\n");
                set("weapon_prop/attack", 3);
                set("weapon_prop/defense", -2);
        }
	init_halberd(40);
        setup();
}
