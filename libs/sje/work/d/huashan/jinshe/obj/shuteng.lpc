// Room: /d/huashan/jinshe/obj/shuteng.c
// Date: Look 99/03/25

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("树藤",({ "teng", "shuteng" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("material", "bamboo");
                set("long", "这是一根树藤。\n");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(3);
        setup();
}
