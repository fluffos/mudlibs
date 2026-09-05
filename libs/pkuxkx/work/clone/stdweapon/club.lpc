// standard club

#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一条很粗却不失弹性的木棍。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);

		set("unit", "条");
		set("material", "wood");
		set("rigidity", 300);
		set("wield_msg", "只听『呼』的一声，$N手中已经多了一条$n。\n");
		set("unwield_msg", "$N将$n随手放下。\n");
	}

	init_club(30);

	setup();
}
