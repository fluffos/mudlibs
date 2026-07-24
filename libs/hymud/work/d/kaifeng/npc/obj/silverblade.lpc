//silverblade.c
//LOTS 1998/10/14
#include <weapon.h>

inherit BLADE;

void create()
{
set_name("银刀", ({ "silverblade", "blade", "dao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 8000);
		set("material", "silver");
		set("long", "这是一把半尺多长的银刀,你拿在手里一掂,正合手\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
		set("shaolin",1);
	}
	init_blade(575);
	setup();
}
