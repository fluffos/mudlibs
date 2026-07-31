// longsword.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("灵剑", ({ "yusui dao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一把灵剑。\n");
		set("value", 2);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_sword(2000);
	setup();
}
