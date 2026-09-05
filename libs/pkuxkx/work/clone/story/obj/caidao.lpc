//chadao.c 菜刀

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("菜刀", ({ "cai dao","dao" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
   	else {
		set("unit", "柄");
		set("long", "一把锋利的菜刀，是厨师常用的工具。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声从腰带中抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n别在腰带上。\n");
	}
	init_blade(20);
	setup();
}
