// longsword.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("魔煞熊爪", ({ "mosha xiongzhua"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "这是一双熊爪。\n");
		set("value", 2);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_sword(500);
	setup();
}
