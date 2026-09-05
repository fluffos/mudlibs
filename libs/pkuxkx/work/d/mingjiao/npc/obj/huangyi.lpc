#include <armor.h>
inherit CLOTH;
void create()
{
    set_name("黄衣", ({"huang", "huang yi"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地非常粗糙的黄色布衣。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
