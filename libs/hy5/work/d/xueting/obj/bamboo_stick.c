// bamboo_stick.c
// by pian

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("竹棍", ({ "bamboo stick", "stick" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"这是一把练习棍法用的竹棍。\n");
                set("wield_msg", "$N拿出一把练功用的$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_staff(17);
        setup();
}
 
