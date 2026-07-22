// blade.c

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("板斧",({"ban fu","banfu","fu","axe"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",500);
		set("material", "tie");
		set("long","一把较轻的板斧。\n");
		set("wield_msg","$N从腰间拔出一把沉甸甸的$n握在手中。\n");
		set("unequip_msg","$N将手中的$n插于腰间。\n");
	}
	init_axe(15);
	setup();
}
