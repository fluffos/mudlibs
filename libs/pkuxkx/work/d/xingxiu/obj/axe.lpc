//gangfu.c 钢斧
#include <weapon.h>
#include <ansi.h>

inherit AXE;


void create()
{
        set_name("大斧头",({ "da futou", "fu", "axe"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("wield_msg", "$N吃了地举起了一把大斧头。\n");
                set("long", "这是一把锈迹斑斑的大斧头。\n");                
                set("unwield_msg", "$N把大斧头抗在了肩上。\n");                
			}
        init_axe(1);
        setup();
}
