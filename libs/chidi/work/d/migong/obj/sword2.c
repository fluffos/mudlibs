#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIC"青虹剑"NOR, ({ "sword", "jian" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄精钢制成的宝剑，看起来异常锋利。\n");
		set("value", 500000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(200);
	setup();
}
