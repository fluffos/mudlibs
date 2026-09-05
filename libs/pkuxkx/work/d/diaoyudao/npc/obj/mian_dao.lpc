// mian dao
// by pretty

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIC "缅刀" NOR, ({ "mian dao", "dao", "blade" }) );
	set_weight( 4000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是倭寇常用的一种刀，刀身狭长，锋利无比。\n");
		set("unit", "柄");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", "$N唰地一声抽出一柄$n握在手中，刀光映着$N的脸，显得异常诡异。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}

	init_blade(50);
	setup();
}
