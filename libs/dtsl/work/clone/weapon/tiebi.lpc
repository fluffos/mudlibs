//bi.c 判官笔
#include <weapon.h>
#include <ansi.h>

inherit BRUSH;
inherit F_UNIQUE;

void create()
{
        set_name("铁笔",({ "tie bi", "bi","brush" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
            set("value", 1500);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("wield_msg", "$N从怀中掏出一只铁笔。\n");
                set("long", "这是一只上好铁打制而成的铁笔。\n");                
                set("unwield_msg", "$N把铁笔放入怀中。\n");                
        }
        init_brush(25);
        setup();
}
