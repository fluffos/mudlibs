// heiyi.c
// by dicky

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("บฺาย", ({ "hei yi", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ผþ");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
