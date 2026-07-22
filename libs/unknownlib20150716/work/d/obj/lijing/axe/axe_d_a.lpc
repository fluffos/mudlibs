#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIC"魔兽破山斧"NOR, ({ "axe","fu"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
		set("value", 500000);
                set("no_put",1);
                set("no_zm",1);
                set("weapon_prop/intelligence", 3);
		set("long", "据说可以增加使用者的智慧。这是一件传说中的神器。\n");
		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_axe(170+random(20));
	setup();
}
