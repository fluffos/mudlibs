
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("拐棍", ({ "guai gun","gun"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根老人用的拐棍。\n");	
		set("material", "steel");
		set("wield_msg", "$N提起一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n扛到了肩上。\n");
	}
	init_staff(50);
	setup();
}
