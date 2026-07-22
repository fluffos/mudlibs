// twig.c
// By jpei
// Modify By River@SJ
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIG"枝条"NOR, ({ "zhi tiao", "twig", "zhi" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枝");
		set("long", "这是树上的枝条。\n");
		set("value", 1);
		set("material", "wood");
                set("wield_msg", "$N拿出一枝$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_sword(1);
}
