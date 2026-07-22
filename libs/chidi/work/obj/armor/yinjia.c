#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("Òø¼×", ({ "yinjia","jia" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 2000);
                set("material", "steel");
                set("armor_prop/armor", 25);
        }
        setup();
}
