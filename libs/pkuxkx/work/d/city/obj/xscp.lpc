// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("玄色长袍", ({ "xuanse changpao","changpao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一件普普通通的长袍。");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value",10000);
           }
        setup();
}

