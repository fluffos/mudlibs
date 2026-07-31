// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("黑陨刀·死寂", ({ "heyd sis" }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄黑陨刀。\n");
		set("value", 10);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(25000);
	setup();
}
