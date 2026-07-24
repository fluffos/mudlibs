// gangdao.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("魔法长剑", ({ "magic sword" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把亮晃晃的魔法长剑，旅行者的常备武器。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回鞘。\n");
	}
	init_sword(200);
	setup();
}
