// guanfu.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIC"三品内侍官服"NOR, ({ "guan fu", "fu", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一件东厂高级官员才有资格穿的宦官服。\n");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

