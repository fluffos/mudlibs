// si_cloth.c
//
// By Kayin @ CuteRabbit Studio 99-4-16 22:18 new
#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"°×É«Ë¿ÒÂ"NOR, ({ "si_cloth" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "silk");
                set("armor_prop/armor", 1);
                set("armor_prop/dodge",10);
        }
        setup();
}

