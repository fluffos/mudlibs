#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("บฺาย", ({ "black cloth","cloth" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ผþ");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value",4000);
        }
        
}       
