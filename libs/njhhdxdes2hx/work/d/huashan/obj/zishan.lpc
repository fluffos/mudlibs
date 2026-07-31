// zishan.c 紫色长衫
// By Marz

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("紫色长衫", ({"shan", "cloth", "chang shan"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
            set("female_only", 1);
        set("unit", "件");
                set("long", "这是件质地轻软的紫色长衫，边上还镂着花呢。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
