
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("钢枪", ({ "spear" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",1500);
		set("material", "iron");
		set("wield_msg", "$N抽出一柄$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n放到了地上。\n");
	}
	init_club(100);
	setup();
}
