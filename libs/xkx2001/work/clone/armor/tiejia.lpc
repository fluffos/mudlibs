//Cracked by Roath
// tiejia.c 铁甲
//

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIC"铁甲"NOR, ({ "armor" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "iron");
		set("value", 2500);
                set("armor_prop/armor", 50);
        }
        setup();
}

