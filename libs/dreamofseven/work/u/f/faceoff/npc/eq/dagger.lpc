// dagger.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("匕首", ({ "dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把看起相當普通的匕首。\n");
		set("value", 50);
		set("material", "steel");
	}
	init_dagger(4);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N從懷中摸出一把$n握在手中。\n");
	set("unwield_msg", "$N將手中的$n藏入懷中。\n");

// The setup() is required.

	setup();
}
