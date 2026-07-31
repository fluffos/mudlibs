// xiao.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("小楼一夜听春雨", ({ "dao", "xiao", "blade" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("material", "gold");
		set("long", "它就是传说中的'圆月弯刀'.\n");
		set("wield_msg", "$N唰的抽出一把$n\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
		set("shaolin",1);
	}
	init_blade(750);
	setup();
}
