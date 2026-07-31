#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("影杖", ({ "staff" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "无数邪气凝聚而成的一根长杖。\n");
		set("no_get", 1);
		set("material", "邪气");
		set("wield_msg", "$N拿出一根$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(10);
	setup();
}

