// cloth3.c
//
// create by zine 30 Aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("皮甲", ({ "pi jia", "jia", "pijia" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
        setup();
}

