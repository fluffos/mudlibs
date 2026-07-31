// bamboo_sword.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("竹刀",({ "zhudao", "dao", "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("material", "bamboo");
                set("long", "这是一把练习剑法用的竹刀。\n");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_blade(25);
        setup();
}

