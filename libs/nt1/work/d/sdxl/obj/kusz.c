// da-shugan.c

#include <weapon.h>
 

inherit SWORD;

void create()
{
        set_name("枯树枝",({ "ku shuzhi", "shuzhi" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("material", "bamboo");
                set("long", "这是一根干枯的树枝。\n");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
           init_sword(15);
        setup();
}
