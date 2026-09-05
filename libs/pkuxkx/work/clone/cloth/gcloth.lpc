// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(CYN+"工匠袍"+NOR, ({"gongjiang pao","pao","cloth" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","这是一件灰色的短袍，有身份的工匠才能穿上。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

