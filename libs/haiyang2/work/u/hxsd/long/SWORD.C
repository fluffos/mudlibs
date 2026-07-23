// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("倚天剑", ({ "yitian sword" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
        	set("long", "这是天下第一利器，有“倚天不出，谁与争锋”之说。\n");
		set("value", 400);
		set("material", "steel");
	}
        init_sword(99);

// These properties are optional, if you don't set them, it will use the
// default values.

        	set("wield_msg","直如矫龙吞水，长虹冠日一般，$n已在$N手中，天地为之变色。\n");
        	set("unwield_msg", "$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。\n");

// The setup() is required.

	setup();
}
