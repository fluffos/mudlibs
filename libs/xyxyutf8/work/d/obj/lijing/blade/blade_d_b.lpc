#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIC"天残月弯刀"NOR, ({"blade","dao"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500000);
                set("no_put",1);
                set("no_zm",1);
		set("material", "iron");
		set("weapon_prop/strength", 20);
		set("long", "充满了神力。这是一件传说中的神器。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(170+random(20));
	setup();
}
