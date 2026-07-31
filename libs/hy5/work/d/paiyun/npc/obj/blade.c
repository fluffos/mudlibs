// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("牛耳大砍刀", ({ "kan dao" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("value", 500);
		set("material", "iron");
		set("long", "这是一把明晃晃的牛耳大砍刀，刀柄下还坠着一缕红缨穗。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n别入腰间。\n");
	}
	init_blade(70);
	setup();
}