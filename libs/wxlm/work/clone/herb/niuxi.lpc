// niuqi.c

#include "herb.h"

void create()
{
	set_name(CYN "牛膝" NOR, ({ "niu xi", "herb_niuxi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 2000);
		set("base_weight", 50);
	}
	setup();
}
