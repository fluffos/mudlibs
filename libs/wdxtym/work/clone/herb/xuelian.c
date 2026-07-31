// xuelian.c

#include "herb.h"

void create()
{
	set_name(HIW "Ñ©Á«" NOR, ({ "xuelian", "herb_xuelian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("base_unit", "¶ä");
		set("base_value", 30000);
		set("base_weight", 40);
	}
	setup();
}
