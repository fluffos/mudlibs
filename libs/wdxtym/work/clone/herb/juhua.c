// juhua.c

#include "herb.h"

void create()
{
	set_name(HIY "菊花" NOR, ({ "juhua", "herb_juhua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "朵");
		set("base_value", 60);
		set("base_weight", 20);
	}
	setup();
}
