#include <armor.h>
inherit CLOTH;


void create()
{
        set_name("´Ö²¼ÒÂ", ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ì×");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
