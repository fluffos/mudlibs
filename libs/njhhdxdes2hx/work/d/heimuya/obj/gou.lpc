// hand_axe.c

#include <weapon.h>

inherit HOOK;

void create()
{
        set_name("吴钩", ({ "wu gou", "gou" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "steel");
                set("long","这种铁钩是江宁的特产,极为锋锐\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的束带间。\n");
                set("weapon_prop/attack", 3);
                set("weapon_prop/defense", -2);
        }
	init_hook(34);
        setup();
}
