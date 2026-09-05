// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIR+"火神袍"+NOR, ({"huoshen pao","pao","cloth" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","这是一件大红色的长袍，地位尊崇的大匠才能穿上。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

