#include <weapon.h>

inherit AXE;

void create()
{
	set_name("莲花斧", ({ "lianhua fu", "axe" , "fu" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
		set("long", "这是一把锋利的大斧。\n");
		set("value", 1000000);
//                set("no_put", 1);
//                		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_axe(200, TWO_HANDED);
	setup();
}
