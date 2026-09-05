// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(WHT+"药师袍"+NOR, ({"yaoshi pao","pao","cloth" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","这是一件白色的长袍，有身份的药师才能穿上。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

