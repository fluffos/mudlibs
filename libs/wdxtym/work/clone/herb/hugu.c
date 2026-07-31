// hugu.c

#include "herb.h"

void create()
{
	set_name(HIW "虎骨" NOR, ({ "hu gu", "hugu", "herb_hugu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 10000);
		set("base_weight", 100);
	}
	setup();
}
