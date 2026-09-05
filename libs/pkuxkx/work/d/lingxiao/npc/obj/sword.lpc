#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("长剑", ({ "changjian", "jian", "sword" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄长剑，入手较轻而锋利不减，雪山弟子多使用这种剑。\n");
		set("value", 800);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(25);
	setup();
}