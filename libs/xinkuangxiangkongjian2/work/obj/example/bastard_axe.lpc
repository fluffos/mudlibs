// bastard_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("重型破坏之斧", ({ "bastard axe", "axe" }) );
	set_weight(37000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把极其沈重的战斧。\n");
		set("value", 7400);
		set("material", "steel");
	}
	init_axe(65);

// These properties are optional, if you don't set them, it will use the
// default values.

	setup();
}
