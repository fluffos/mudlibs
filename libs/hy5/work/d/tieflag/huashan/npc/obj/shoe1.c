 // shoe.c
#include <armor.h> 
inherit BOOTS; 
void create()
{
        set_name("²ÝÐ¬", ({ "shoes" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("material", "cloth");
        }
setup();
}
