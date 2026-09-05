// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("破布衣", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
				set("long","这是一件染着油污的布衣，补丁加上补丁，破烂不堪。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

