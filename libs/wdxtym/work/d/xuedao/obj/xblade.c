// xue-dao.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIR "血刀" NOR, ({ "blood blade", "blade" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", HIR "这是一把可缠在腰间的柔韧的缅"
			    "刀，刀锋带着淡淡的血影，一片暗红。"NOR"\n" );
		set("value", 200000);
	    // set("icon", "05038");
		set("material", "steel");
		set("no_sell", "这个... 这个有点古怪...");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(120);
	setup();
}
