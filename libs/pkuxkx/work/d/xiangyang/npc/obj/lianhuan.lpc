#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(RED"连环甲"NOR, ({ "lianhuan jia","jia","armor" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
                set("value", 200000);
                set("armor_prop/armor", 124);
        }
        setup();
}

