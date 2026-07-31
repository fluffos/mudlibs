// taozhi_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("桃枝",({ "tao zhi", "zhi", "tao" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 0);
                set("material", "bamboo");
                set("long", "这是一条桃枝。\n");
                set("wield_msg", "$N拿出一条$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(1);
        setup();
}

