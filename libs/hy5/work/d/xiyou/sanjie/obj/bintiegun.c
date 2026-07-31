// bintiegun.c 镔铁棍

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("镔铁棍", ({ "bintiegun","tiegun","gun", "bang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 100);
		set("material", "steel");
		set("long", "一根沉甸甸黑黝黝的镔铁棍。\n");
		set("wield_msg", "$N拿起一根$n，顺手舞了个棍花。\n");
		set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
	}
	init_staff(35);
	setup();
}
