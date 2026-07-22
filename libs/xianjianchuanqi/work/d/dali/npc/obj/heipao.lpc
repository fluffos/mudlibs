// heipao.c 黑袍

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("黑袍", ({ "hei pao", "pao" ,"cloth" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
                set("armor_prop/armor", 50);
        }
        setup();
}

