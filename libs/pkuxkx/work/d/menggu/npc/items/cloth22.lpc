// cloth2.c
//
// create by zine 30 Aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(YEL"皮袄"NOR, ({ "pi ao", "ao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

