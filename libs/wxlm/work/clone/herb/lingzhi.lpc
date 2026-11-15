// lingzhi.c

#include "herb.h"

void create()
{
	set_name(HIG "灵芝" NOR, ({ "lingzhi", "herb_lingzhi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 20000);
		set("base_weight", 70);
	}
	setup();
}
