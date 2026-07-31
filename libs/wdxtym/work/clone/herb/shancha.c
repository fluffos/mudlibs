// shancha.c

#include "herb.h"

void create()
{
	set_name(WHT "山茶花" NOR, ({ "shancha", "herb_shancha" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "朵");
		set("base_value", 200);
		set("base_weight", 20);
	}
	setup();
}
