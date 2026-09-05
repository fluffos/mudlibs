// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("貂裘", ({ "diao qiu","qiu","fur" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
				set("long","这是一件通体漆黑的貂裘，全无一丝杂毛。\n");
                set("material", "fur");
				set("is__diao__qiu",1);
                set("armor_prop/armor", 50);
        }
        setup();
}

