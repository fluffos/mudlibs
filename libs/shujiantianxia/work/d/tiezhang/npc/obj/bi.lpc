//bi.c 判官笔
#include <weapon.h>
#include <ansi.h>

inherit BRUSH;
inherit F_UNIQUE;

void create()
{
        set_name("镔铁判官笔",({ "panguan bi", "bi" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("wield_msg", "$N从怀中掏出一把镔铁判官笔。\n");
                set("long", "这是一把上好铁打制而成的镔铁判官笔。\n");                
                set("unwield_msg", "$N把镔铁判官笔放入怀中。\n");                
        }
        init_brush(30);
        setup();
}
