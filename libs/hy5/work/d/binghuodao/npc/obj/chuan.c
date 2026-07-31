// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Ä¾·¤", ({ "mufa" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "skin");
               set("value",0);
               set("armor_prop/armor", 3);
        }
        setup();
}

