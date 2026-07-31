#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("扫帚",({"saozhou","sao zhou"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long","红棕编制成的扫帚，扫地用的。\n");
	set("material","wood");
	}
	init_staff(35);


	setup();
}
