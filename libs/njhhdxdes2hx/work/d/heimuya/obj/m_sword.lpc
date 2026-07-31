// longsword.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("木剑", ({ "sword", "mu jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的木剑\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(2);
	setup();
}
