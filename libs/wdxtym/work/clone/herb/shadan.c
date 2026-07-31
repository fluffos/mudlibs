#include "herb.h"

void create()
{
	set_name(HIB "öèµ¨" NOR, ({ "sha dan", "herb_shadan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖĞÒ©Ò©²Ä¡£\n");
		set("base_unit", "¿é");
		set("base_value", 10000);
		set("base_weight", 35);
	}
	setup();
}

