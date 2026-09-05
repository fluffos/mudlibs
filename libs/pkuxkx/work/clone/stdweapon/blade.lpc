// standard blade

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一把精钢打造的利刃。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);
		set("unit", "把");
		set("material", "steel");
		set("rigidity", 300);
		set("wield_msg", "$N『唰』的一声抽出一把$n握在手里。\n");
		set("unwield_msg", "$N将$n插回鞘中。\n");
	}

	init_blade(30);

	setup();
}
