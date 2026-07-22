//gangfu.c 钢斧
#include <weapon.h>
#include <ansi.h>

inherit AXE;
inherit F_UNIQUE;

void create()
{
        set_name("钢斧",({ "gang fu", "fu", "axe"}) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 2000);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("wield_msg", "$N唰地一声从腰中抽出一把钢斧。\n");
                set("long", "这是一普普通通的钢斧。\n");                
                set("unwield_msg", "$N把钢斧别在了腰中。\n");                
        }
        init_axe(30);
        setup();
}
