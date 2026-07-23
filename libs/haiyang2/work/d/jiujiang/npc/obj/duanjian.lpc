
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("短剑", ({ "duan jian","jian","sword" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把短剑。\n");
		set("value", 2000);
		set("material", "steel");
	}
	init_sword(70);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插回腰间的剑鞘。\n");

	setup();
}
