// steel_fork.c

#include <weapon.h>

inherit FORK;

void create()
{
	set_name("五股钢叉", ({ "fork" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 3400);
		set("material", "steel");
                set("long","一把五股钢叉,锋刃冒着寒气令人不寒而栗!\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背後的长囊间。\n");

	}
	init_fork(50);

	setup();
}
