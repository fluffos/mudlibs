//Cracked by Kafei
#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(MAG"紫金刀"NOR, ({ "zijin dao", "dao" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一柄厚背薄刃紫金刀，刃上紫光闪闪，冷气森森。\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 500);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(250);
	setup();
}
