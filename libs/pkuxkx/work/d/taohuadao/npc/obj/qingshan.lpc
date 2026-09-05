// qingshan.c 青衫

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("青衫", ({"qing shan", "shan", "cloth"}));
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
            set("male_only", 1);
        set("unit", "件");
        set("long", "这是一件青色的长衫。 \n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
