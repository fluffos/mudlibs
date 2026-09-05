// standard whip

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name( color + "名字" + NOR , ({ "ＩＤ" }) );
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一条柔韧的皮鞭。\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("auto_load", 1);

		set("unit", "条");
		set("material", "leather");
		set("rigidity", 300);
		set("wield_msg", "$N『嗖』的一声从腰间抽出一条$n。\n");
		set("unwield_msg", "$N将$n卷回腰间。\n");
	}

	init_whip(30);

	setup();
}
