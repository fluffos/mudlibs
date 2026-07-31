// fuzi.c

#include "herb.h"

void create()
{
	set_name(WHT "附子" NOR, ({ "fu zi", "herb_fuzi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "粒");
		set("base_value", 1000);
		set("base_weight", 20);
	}
	setup();
}
