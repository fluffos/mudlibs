#include <weapon.h>
#include <ansi.h>

inherit AXE;
int is_KARMA_AXE()
{
	return 1;
}
void create()
{
	set_name("斧头",({ "fu tou", "fu", "axe"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("wield_msg", "$N抓起了一把斧头。\n");
                set("long", "这是一把单手斧，可以用来做一些简单的劳动。\n");                
                set("unwield_msg", "$N把斧头别在了腰中。\n");                
			}
	init_axe(5);
	setup();
}
