#include <armor.h>
inherit CLOTH; 
void create()
{
    set_name("บฺาย", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("material", "cloth");
                set("unit", "ผþ");
                set("value", 100);
                set("armor_prop/armor", 1);
        }
        
}       
