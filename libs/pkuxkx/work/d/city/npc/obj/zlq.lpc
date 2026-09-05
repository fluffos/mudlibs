// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("紫罗裙", ({ "ziluo qun","qun" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一件深受少女们喜欢的紫色罗裙。");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value",20000);
           }
        setup();
}

