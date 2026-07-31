// yuanzhi.c

#include "herb.h"

void create()
{
	set_name(HIB "远志" NOR, ({ "yuan zhi", "herb_yuanzhi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 3000);
		set("base_weight", 75);
	}
	setup();
}
