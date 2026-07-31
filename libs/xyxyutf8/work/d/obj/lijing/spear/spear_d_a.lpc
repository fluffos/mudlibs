#include <weapon.h>
#include <ansi.h>
inherit SPEAR;
void create()
{
	set_name(HIC"布都御魂枪"NOR, ({ "spear","qiang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("value", 500000);
                set("no_put",1);
                set("no_zm",1);
		set("material", "wood");
		set("weapon_prop/intelligence", 3);
		set("long", "这是一件传说中的神器。\n");
		set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
		set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
	}
	init_spear(170+random(20));
	setup();
}
