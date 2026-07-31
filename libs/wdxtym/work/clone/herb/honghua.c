// honghua.c

#include "herb.h"

void create()
{
	set_name(HIR "红花" NOR, ({ "honghua", "herb_honghua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "朵");
		set("base_value", 80);
		set("base_weight", 20);
	}
	setup();
}
