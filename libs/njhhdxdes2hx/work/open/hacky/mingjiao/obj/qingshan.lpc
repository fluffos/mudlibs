// qingshan.c 青色长衫
// By yuer

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("青色长衫", ({"shan", "cloth", "chang shan"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地粗糙的青色长衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}

