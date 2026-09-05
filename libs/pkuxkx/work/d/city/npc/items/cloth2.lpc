// cloth.c
// 皮甲 zine 2 aug 2010


#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("皮甲", ({ "pi jia" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
                set("armor_prop/armor", 50);
        }
        setup();
}

