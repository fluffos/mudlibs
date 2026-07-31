#include <armor.h>
inherit HEAD;
void create()
{
        set_name("≤ √±", ({ "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "∂•");
        set("material", "cloth");
        set("armor_prop/armor", 10);
        }
        
} 
