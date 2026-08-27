// Last Modified by winder on Apr. 25 2001
// wandao.c
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("蒙古彎刀", ({ "wan dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "這是一柄亮晃晃的鋼刀，是蒙古官兵的常備武器。\n");
		set("value", 29);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插回刀鞘。\n");
	}
	init_blade(30);
	setup();
}

