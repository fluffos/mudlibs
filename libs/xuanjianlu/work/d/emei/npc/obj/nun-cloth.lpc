//Cracked by Roath
// nun-cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("青布缁衣", ({ "zi yi", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 8);
        }
        setup();
}

