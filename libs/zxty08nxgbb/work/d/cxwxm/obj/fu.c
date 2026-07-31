//marry 8.13
#include <weapon.h>

inherit AXE;

void create()
{
        set_name("开山斧", ({ "fu" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 200);
                set("material", "iron");
                set("long", "这是一柄开山斧。\n");
                set("wield_msg", "$N从背后拔出一柄亮晃晃$n握在手中　\n");
                set("unequip_msg", "$N将手中的$n插在背后。　\n");
        }
        init_axe(15);
        setup();
}

