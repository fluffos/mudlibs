// gangdao.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"天使长剑"NOR, ({ "angel sword" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把亮晃晃的天使长剑。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回鞘。\n");
	}
	init_sword(390);
	setup();
}
