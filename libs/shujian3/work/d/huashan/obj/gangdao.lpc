// ITEM: /d/huashan/obj/gangdao.c
// Date: Look 99/03/25

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("钢刀", ({ "blade", "dao" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄精工制成的钢刀，这种剑在将领之间非常流行。\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(30);
	setup();
}
