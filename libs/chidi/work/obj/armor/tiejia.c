// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("Ìú¼×",({"tiejia","jia"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material","iron");
                set("armor_prop/armor",20);
                set("value",1000);
        }
        setup();
}
