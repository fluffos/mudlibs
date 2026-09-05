// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIM"锦衣"NOR, ({ "jin yi","yi","cloth" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

