//marry 8.13
#include <weapon.h>

#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIW"妄想斧"NOR, ({ "axe" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 200);
                set("material", "iron");
                set("long", "这是痴心妄想门特制的手斧。\n");
                set("wield_msg", "$N从背后拔出一柄亮晃晃$n握在手中　\n");
                set("unequip_msg", "$N将手中的$n插在背后。　\n");
        }
         init_axe(250);
        setup();
}
