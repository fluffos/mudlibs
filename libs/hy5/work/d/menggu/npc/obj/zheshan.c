// Mr.music  yangzhou's 扇子

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("檀香扇",({"shanzi"}));
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 100);
		set("material", "steel");
		set("long", "这是一柄看来很普通的扇子。\n");
		set("wield_msg", "$N唰的一声甩开了扇子。\n");
		set("unequip_msg", "$N收起手中的$n。\n");
		set("weapon_prop/courage", -4);
	}
	init_sword(20);
	setup();
}
