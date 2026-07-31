// blade.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name("板斧",({"banfu","ban fu","fu","axe"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",5000);
		set("material", "iron");
		set("long","一把较轻的板斧。\n");
		set("wield_msg","$N从腰间拔出一把沉甸沉的$n握在手中。\n");
		set("unequip_msg","$N将手中的$n插于腰间。\n");
	}
	init_axe(20);
	setup();
}
