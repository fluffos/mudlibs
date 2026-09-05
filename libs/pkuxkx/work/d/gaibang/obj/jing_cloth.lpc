// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("旧布衣", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
				set("long","这是一件旧衣，虽然打着补丁，但却还是很干净。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

