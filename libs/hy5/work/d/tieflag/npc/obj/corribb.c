 // icy_band.c
#include <ansi.h>
#include <armor.h> 
inherit NECK; 
void create()
{
        set_name(  "²Ê½í" , ({ "color ribbon", "ribbon" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "Ìõ");
        set("value", 400);
        set("material", "cloth");
        set("armor_prop/armor", 1);
        }
        
}       
