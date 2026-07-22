#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIW"冷月宝刀"NOR, ({ "baodao" , "lengyue baodao" , "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄刀面平如湖水的宝刀。\n");
		set("value", 1000000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(250);
	setup();
}
