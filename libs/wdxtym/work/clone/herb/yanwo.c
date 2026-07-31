#include "herb.h"

void create()
{
	set_name(HIW "ÑàÎÑ" NOR, ({ "yan wo", "herb_yanwo" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖĞÒ©Ò©²Ä¡£\n");
		set("base_unit", "¿é");
		set("base_value", 50000);
		set("base_weight", 35);
	}
	setup();
}

