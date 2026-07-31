// xiefen.c

#include "herb.h"

void create()
{
	set_name(HIM "蝎粉" NOR, ({ "xiefen", "herb_xiefen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "包");
		set("base_value", 500);
		set("base_weight", 35);
	}
	setup();
}
