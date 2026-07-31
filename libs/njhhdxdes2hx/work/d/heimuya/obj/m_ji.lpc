// hand_axe.c

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("木戟", ({ "mu ji", "ji" }) );
        set_weight(8500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 50);
                set("material", "steel");
                set("long","一把木戟\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背後的长囊间。\n");
        }
	init_halberd(1);
        setup();
}
