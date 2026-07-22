//mayi.c 灰衣
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL"麻衣"NOR, ({"ma yi", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                 set("armor_prop/armor", 50);
        }
        setup();
}
