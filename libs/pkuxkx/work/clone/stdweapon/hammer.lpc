// standard hammer

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一柄沉甸甸的铁锤。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);
		set("unit", "柄");
		set("material", "iron");
		set("rigidity", 300);
		set("wield_msg", "$N拿出一柄$n，试了试重量，然后握在手里。\n");
		set("unwield_msg", "$N把$n插回背后。\n");
	}

	init_hammer(30);

	setup();
}
