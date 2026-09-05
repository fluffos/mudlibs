// standard staff

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一条精铁打造的禅杖。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);
		set("unit", "条");
		set("material", "iron");
		set("rigidity", 300);
		set("wield_msg", "$N『呼』的一声抽出一条$n握在手中。\n");
		set("unwield_msg", "$N将$n随手放下。\n");
	}

	init_staff(30);

	setup();
}
