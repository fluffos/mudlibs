// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ÊÞÆ¤ÒÂ", ({ "skincloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "skin");
                set("armor_prop/armor", 3);
        }
        setup();
}

