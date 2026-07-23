// hupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("虎皮", ({ "hupi","pi" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
