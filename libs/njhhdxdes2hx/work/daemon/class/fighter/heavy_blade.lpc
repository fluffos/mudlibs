// heavy_blade.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name( "大环刀", ({ "heavy blade", "blade" }) );
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把沈重的大环刀，上面镶著十四个钢环。\n");
		set("value", 1200);
		set("material", "steel");
		set("wield_msg", "只听见「呛□□」一阵金属声响，$N的手中多了一把精光四射的大环刀。\n");
		set("unequip_msg", "$N将手中的$n挂在背後的刀□上。\n");
	}

	init_blade(40);
	setup();
}
