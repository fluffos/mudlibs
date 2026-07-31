#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("╟в╫С╨зию", ({ "black clothes", "clothes" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "╪Ч");
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("value",4000);
        }
    
}   
