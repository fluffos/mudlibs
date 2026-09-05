// standard dagger

#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一柄精光四射的匕首。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);

		set("unit", "柄");
		set("material", "steel");
		set("rigidity", 300);
		set("wield_msg", "$N从怀中摸出一柄$n握在手里。\n");
		set("unwield_msg", "$N将$n藏入怀中。\n");
	}

	init_dagger(10);

	setup();
}
