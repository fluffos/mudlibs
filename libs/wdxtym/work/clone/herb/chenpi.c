// chenpi.c

#include "herb.h"

void create()
{
	set_name(YEL "³ÂÆ¤" NOR, ({ "chenpi", "herb_chenpi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("base_unit", "¿é");
		set("base_value", 10);
		set("base_weight", 20);
	}
	setup();
}
