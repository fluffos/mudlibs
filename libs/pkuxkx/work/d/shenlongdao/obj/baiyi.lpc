//白衣 
//by kiden
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(HIW"白衣"NOR, ({"bai yi", "baiyi", "cloth"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地轻软的白衣。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
