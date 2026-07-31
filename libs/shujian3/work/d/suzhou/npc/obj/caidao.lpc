// caidao.c 菜刀

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("菜刀", ({ "cai dao", "dao" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的做饭用的菜刀。\n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声从腰间抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n别在腰中。\n");
	}
	init_blade(15);
	setup();
}
