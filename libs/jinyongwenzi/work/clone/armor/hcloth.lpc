// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("黄葛布衫", ({ "gebu shan", "shan"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件黄赫色葛布长衫\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value", 0);
        }
        setup();
}

