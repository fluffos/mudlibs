//青衣 
//by kiden
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(HIC"青衣"NOR, ({"qing yi", "qingyi", "cloth"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地轻软的青衣。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
