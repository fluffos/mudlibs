//writen by lnwm
//daopao.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("À¶²¼µÀÅÛ", ({ "daopao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}

