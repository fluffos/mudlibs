// cracked by vikee 2/09/2002   vikee@263.net
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("皮袍", ({"pipao"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 800);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

