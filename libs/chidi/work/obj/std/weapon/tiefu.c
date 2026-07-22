// blade.c

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("铁斧",({"tie fu","tiefu","fu","axe"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",1000);
		set("material", "tie");
		set("long","一把沉甸甸闪着金光的铁斧。\n");
		set("wield_msg","$N从腰间拔出一把沉甸甸的$n握在手中。\n");
		set("unequip_msg","$N将手中的$n插于腰间。\n");
	}
	init_axe(25);
	setup();
}
