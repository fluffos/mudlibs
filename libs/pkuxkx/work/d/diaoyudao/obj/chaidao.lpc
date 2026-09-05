// chaidao.c 柴刀

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("柴刀", ({ "chai dao","dao" }));
	set_weight(6000);
//	if (clonep())
//		set_default_object(__FILE__);
//	else {
		set("unit", "柄");
		set("long", "一柄锈迹斑斑的破柴刀，是寻常贫民常备的工具。\n");
//		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
//	}
	init_blade(20);
	setup();
}
