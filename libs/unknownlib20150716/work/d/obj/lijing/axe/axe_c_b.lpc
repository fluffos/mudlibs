#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIY"紫云巨斧"NOR, ({ "axe","fu"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
		set("value", 200000);
                set("no_put",1);
                set("no_zm",1);
                set("weapon_prop/strength", 10);
		set("long", "充满了神力。这是一件上古宝物。\n");
		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_axe(145);
	setup();
}
