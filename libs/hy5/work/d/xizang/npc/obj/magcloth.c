#include <armor.h>
inherit CLOTH; 
void create()
{
        set_name("воию", ({ "cloth" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "╪Ч");
                set("material", "cloth");
                set("armor_prop/armor", 6);
        }
        
}
