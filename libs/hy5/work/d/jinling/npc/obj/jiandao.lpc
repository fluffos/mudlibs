// brass_staff.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("剪刀", ({ "jian dao" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把普普通通的剪刀。\n");
		set("value", 120);
		set("material", "steel");
		set("wield_msg", "$N拿出一把$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_blade(10);
	setup();
}
