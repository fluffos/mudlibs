// chenpi.c

#include "herb.h"

void create()
{
	set_name(YEL "陈皮" NOR, ({ "chenpi", "herb_chenpi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 10);
		set("base_weight", 20);
	}
	setup();
}
