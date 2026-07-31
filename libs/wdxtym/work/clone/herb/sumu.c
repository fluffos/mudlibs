// sumu.c

#include "herb.h"

void create()
{
	set_name(WHT "苏木" NOR, ({ "su mu", "herb_sumu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 5000);
		set("base_weight", 60);
	}
	setup();
}
