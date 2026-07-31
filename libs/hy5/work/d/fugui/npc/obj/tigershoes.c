#include <armor.h>
inherit BOOTS; 
void create()
{
        set_name( "»¢Í·Ð¬", ({ "tiger shoes", "shoes"}) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "Ë«");
                set("value", 300);
                set("armor_prop/armor", 1 );
                set("female_only", 1);
        }
        
}  
