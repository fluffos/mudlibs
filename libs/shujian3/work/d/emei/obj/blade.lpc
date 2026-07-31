// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(GRN"柳叶刀"NOR, ({ "liuye dao", "blade" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄柳叶刀。\n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(25);
	setup();
}
