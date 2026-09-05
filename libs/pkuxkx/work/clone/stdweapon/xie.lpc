// standard xie

#include <ansi.h>
#include <weapon.h>

inherit XIE;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一双坚硬无比的铁鞋。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);
		set("unit", "双");
		set("material", "iron");
		set("wield_msg", "$N将一双$n套在脚上。\n");
		set("unwield_msg", "$N把$n脱下收了起来。\n");
	}

	init_xie(30);

	setup();
}
