// heshouwu.c

#include "herb.h"

void create()
{
	set_name(HIW "何首乌" NOR, ({ "shouwu", "herb_heshouwu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 10000);
		set("base_weight", 85);
	}
	setup();
}
