// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("短刀", ({ "duan dao","dao" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的弯刀，各门派的常备武器。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(20);
	setup();
}
