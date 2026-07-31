// bamboo_blade.c
// by pian

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("竹刀", ({ "bamboo blade", "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"这是一把练习剑法用的竹刀，刀尖处用布包了起来以免误伤同伴。\n");
                set("wield_msg", "$N拿出一把练习用的$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_blade(10);
        setup();
}
 
