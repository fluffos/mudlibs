// brass_staff.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("琵琶", ({ "pipa", "staff" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条做工精美的琵琶。\n");
		set("value", 1200);
		set("material", "steel");
		set("wield_msg", "$N拿出一条精美的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(110);
	setup();
}
