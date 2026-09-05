//lingsuo.c 铃索

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("铃索", ({ "lingsuo", "whip" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是一条白缎，末端系着一个金铃。\n");
		set("value", 15000);
		set("material", "cloth");
		set("wield_msg", "$N从怀中拿出一条铃索握在手中。\n");
		set("unwield_msg", "$N将手中铃索放入怀中。\n");
	}
	init_whip(50);
	setup();
}
