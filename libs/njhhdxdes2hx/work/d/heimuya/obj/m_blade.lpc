// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("木刀", ({ "blade" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","这是一柄木刀，普通教众的练习武器。\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(0);
	setup();
}
