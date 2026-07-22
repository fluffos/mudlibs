// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(HIC"青布女履"NOR, ({ "shoes" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "boots");
		set("female_only", 1);
                set("armor_prop/dodge", 1);
        }
        setup();
}
