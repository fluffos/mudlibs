// shengdi.c生地

#include "herb.h"

void create()
{
	set_name(WHT "生地" NOR, ({ "shengdi", "herb_shengdi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 500);
		set("base_weight", 60);
	}
	setup();
}
