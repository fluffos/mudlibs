// niuhuang.c

#include "herb.h"

void create()
{
	set_name(HIY "Å£»Æ" NOR, ({ "niu huang", "herb_niuhuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("base_unit", "¿Å");
		set("base_value", 1000);
		set("base_weight", 60);
	}
	setup();
}
