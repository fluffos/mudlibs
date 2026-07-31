// longsword.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("獠牙棒", ({ "dongy wusd"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根獠牙棒。\n");
		set("value", 2);
		set("material", "steel");
		set("wield_msg", "$N「帕」的一声抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放回背后。\n");
	}
	init_sword(500);
	setup();
}
