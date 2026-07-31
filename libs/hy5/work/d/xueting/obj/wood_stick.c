// wood_stick.c
// by pian

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("漆黑木棍", ({ "bamboo stick", "stick" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"这是一把乞丐常用的赶狗用的木棍。\n");
                set("wield_msg", "$N拿出一把乞讨用的木棍，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_staff(17);
        setup();
}
 
