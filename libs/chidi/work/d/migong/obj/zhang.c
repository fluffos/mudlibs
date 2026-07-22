#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(BLU"玄铁杖"NOR, ({ "xuantie zhang", "zhang" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根掺有玄铁的钢杖。\n");
		set("value", 1000000);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声提起一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n收回背后。\n");
	}
	init_staff(200);
	setup();
}
