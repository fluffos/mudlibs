#include <weapon.h>
inherit AXE;

void create()
{
	set_name("战斧", ({ "zhan fu", "fu","axe" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄大明制式的战斧，高级武将方可使用。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
		set("no_drop",1);
		set("no_give",1);
		set("no_get","大明的制式战斧，捡了要杀头的。\n");
	}
	init_axe(100+random(25));
	setup();
}
