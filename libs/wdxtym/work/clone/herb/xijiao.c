// xijiao.c

#include "herb.h"

void create()
{
	set_name(WHT "犀角" NOR, ({ "xi jiao", "herb_xijiao" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 10000);
		set("base_weight", 35);
	}
	setup();
}

