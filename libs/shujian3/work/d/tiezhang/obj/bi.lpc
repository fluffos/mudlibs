//bi.c 判官笔
#include <weapon.h>
#include <ansi.h>

inherit BRUSH;
inherit F_UNIQUE;

void create()
{
        set_name("镔铁判官笔",({ "panguan bi", "bi" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 5000);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("wield_msg", "$N从怀中掏出一只镔铁判官笔。\n");
                set("long", "这是一只上好铁打制而成的镔铁判官笔。\n");                
                set("unwield_msg", "$N把镔铁判官笔放入怀中。\n");                
        }
        init_brush(70);
        setup();
}
