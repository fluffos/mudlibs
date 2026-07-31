#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("扁担",({"biandan","bian dan","dan"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("value",50);
	set("long","竹子制成的扁担，挑东西可用得着它。\n");
	set("material","bamboo");
	}
	init_staff(5);


	setup();
}
