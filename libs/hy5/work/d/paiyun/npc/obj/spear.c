// spear.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name( "点钢枪", ({ "spear" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "枝");
		set("long", "一枝两丈多的点钢枪。\n");
		set("value", 500);
		set("material", "iron");
		set("wield_msg", "$N拿起一枝$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");                
	}

	init_club(85);
	setup();
}