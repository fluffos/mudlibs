//红衣 
//by kiden
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(HIR"红衣"NOR, ({"hong yi", "hongyi", "cloth"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地轻软的红衣。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
