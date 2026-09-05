// standard fork

#include <ansi.h>
#include <weapon.h>

inherit FORK;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一杆沉甸甸的钢叉。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);

		set("unit", "杆");
		set("material", "steel");
		set("rigidity", 300);
		set("wield_msg", "$N『呼』的一声摆出一杆$n。\n");
		set("unwield_msg", "$N将$n随手放下。\n");
	}

	init_fork(30);

	setup();
}
