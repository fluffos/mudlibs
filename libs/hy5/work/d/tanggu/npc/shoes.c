// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name("²¼ÂÄ", ({ "shoes" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("material", "boots");
                set("armor_prop/dodge", 1);
        }
        setup();
}
