// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("╡ьеш", ({ "cloth" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "╪Ч");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 50);
        }
        setup();
}

