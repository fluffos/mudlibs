// tianqi.c

#include "herb.h"

void create()
{
	set_name(WHT "田七" NOR, ({ "tianqi", "herb_tianqi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 400);
		set("base_weight", 55);
	}
	setup();
}
