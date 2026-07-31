// tugu_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("剃骨刀", ({ "tigu blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("value", 200);
		set("material", "iron");
		set("long", "这是一把剃骨用的尖刀。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n别入腰间。\n");
	}
	init_blade(60);
	setup();
}