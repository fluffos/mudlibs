#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("Òø¼×", ({ "yinjia","jia" }) );
        set_weight(6);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 2000);
                set("material", "steel");
                set("armor_prop/armor", 25000000);
        }
        setup();
}
