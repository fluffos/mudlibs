#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("干木柴", ({ "woods", "dry woods" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("base_unit", "条");
		set("value",1);
		set("base_weight", 10);
	}
  set_amount(1);
	init_throwing(2);
	setup();
}
