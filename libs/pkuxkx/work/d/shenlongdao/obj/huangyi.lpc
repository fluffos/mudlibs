//黄衣 
//by kiden
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(HIY"黄衣"NOR, ({"huang yi", "huangyi", "cloth"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地轻软的黄衣。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
