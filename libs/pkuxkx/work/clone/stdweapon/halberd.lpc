// standard halberd

#include <ansi.h>
#include <weapon.h>

inherit HALBERD;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一杆精钢打造的方天戟。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);

		set("unit", "杆");
		set("material", "steel");
		set("rigidity", 300);
		set("wield_msg", "$N『呼』的一声摆出一杆$n。\n");
		set("unwield_msg", "$N将$n撤回身后。\n");
	}

	init_halberd(30);

	setup();
}
