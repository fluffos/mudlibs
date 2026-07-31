#include <armor.h>
inherit CLOTH; 
void create()
{
        set_name("´Ö²¼ÂéÒÂ", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("material", "cloth");
                set("unit", "¼þ");
                set("value", 100);
                set("armor_prop/armor", 1);
        }
        
}      
