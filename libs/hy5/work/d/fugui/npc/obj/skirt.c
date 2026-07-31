#include <armor.h>
inherit CLOTH; 
void create()
{
        set_name("Ð¡»¨È¹", ({ "skirt" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("value", 100);
                set("armor_prop/armor", 1);
        }
        
} 
