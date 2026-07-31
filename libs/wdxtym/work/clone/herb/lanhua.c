// lanhua.c

#include "herb.h"

void create()
{
	set_name(HIB "兰花" NOR, ({ "lanhua", "herb_lanhua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "朵");
		set("base_value", 500);
		set("base_weight", 20);
	}
	setup();
}
