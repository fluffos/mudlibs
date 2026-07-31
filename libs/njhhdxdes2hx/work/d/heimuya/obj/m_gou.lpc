// hand_axe.c

#include <weapon.h>

inherit HOOK;

void create()
{
        set_name("木钩", ({ "mu gou", "gou" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 50);
                set("material", "wood");
                set("long","一把木钩\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的束带间。\n");
        }
	init_hook(1);
        setup();
}
