//gangfu.c 钢斧
#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name("铁斧",({ "tie fu", "fu", "axe"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 2000);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("wield_msg", "$N唰地一声从腰中抽出一把铁斧。\n");
                set("long", "这是一普普通通的铁斧。\n");                
                set("unwield_msg", "$N把铁斧别在了腰中。\n");                
        }
        init_axe(20);
        setup();
}
