#include <armor.h>
inherit BOOTS; 
void create()
{
    set_name("²ÝÐ¬", ({"shoes"}));
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else 
    {
        set("material", "leather");
        set("unit", "Ë«");
        set("armor_prop/armor", 1);
    }
    
}   
