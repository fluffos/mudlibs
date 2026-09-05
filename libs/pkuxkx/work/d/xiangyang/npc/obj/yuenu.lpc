#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(GRN"越女剑"NOR, ({ "yuenu jian", "jian","sword" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", GRN"这是一柄小巧轻盈的软剑,虽然轻巧,但削铁如泥。\n"NOR);
                 set("value", 150000);
		set("material", "steel");
		set("wield_msg", GRN"$N「唰」的一声抽出一柄越女剑握在手中,剑尖微颤,剑锋寒气逼人.\n"NOR);
		set("unwield_msg", GRN"$N将手中的越女剑插回剑鞘。\n"NOR);
	}
	init_sword(100);
	setup();
}
