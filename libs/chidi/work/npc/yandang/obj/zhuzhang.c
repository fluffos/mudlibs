#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("枯竹杖" , ({ "staff", "zhuzhang" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根竹杖,由于经常使用,头上已经开裂了。\n");
		set("value", 120);
		set("material", "wood");
		set("wield_msg", "$N拿出一根微黄的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(10);
	setup();
}
