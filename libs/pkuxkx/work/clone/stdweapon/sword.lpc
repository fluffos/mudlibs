// standard sword

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一柄精钢打造的利剑。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);
		set("unit", "柄");
		set("material", "steel");
		set("rigidity", 300);
                set("wield_msg", "$wield_msg$");
                set("unwield_msg", "$unwield_msg$");
	}

	init_sword(30);

	setup();
}
