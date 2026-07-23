
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("软索", ({ "ruansuo", "suo" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根软索，由牛筋混合五金精工编织而成，索的一端是一根铁杆。\n");
		set("value", 100);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(20);
	setup();
}
