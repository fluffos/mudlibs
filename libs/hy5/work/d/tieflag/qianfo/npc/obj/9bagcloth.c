 // TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("¾Å´ü²¼ÒÂ", ({ "9bag-cloth" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value",400);
        }
        
}       
