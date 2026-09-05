// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(CYN"灰袍"NOR, ({ "hui pao","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 15);
        }
		set("long","这是低级太监常穿的灰袍。\n");
        setup();
}

