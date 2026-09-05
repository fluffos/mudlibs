#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("黄色僧衣", ({"seng yi", "cloth", "seng yi"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
                set("long", "一件普普通通的黄色僧衣。\n");
        set("material", "cloth");
        set("armor_prop/armor", 5);
    }
    setup();
}
