// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("左手刀",({"dao"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
		set("material", "iron");
		set("long","这是一寻常的钢刀，伤害力较强。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(159);
	setup();
}
