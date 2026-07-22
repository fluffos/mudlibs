#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("藏刀" , ({ "zhang_blade", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把藏刀,锋利无比。\n");
		set("value", 120);
		set("material", "steel");
		set("wield_msg", "$N抽出一把$n,登时浓重的杀气从刀上散发出来。\n");
		set("unwield_msg", "$N收起手中的$n。\n");
	}

	init_blade(20);
	setup();
}
