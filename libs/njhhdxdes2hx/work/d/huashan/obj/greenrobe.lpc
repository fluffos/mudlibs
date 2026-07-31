// greenrobe.c 绿色长裙
// By Marz

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("绿色长裙", ({"qun", "cloth", "chang qun"}) );
    set_weight(1500);
    if( clonep() )
    set_default_object(__FILE__);
    else {
        set("female_only", 1);
        set("unit", "件");
        set("long", "这是件质地轻软的绿色长裙，边上还镂着花呢。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
