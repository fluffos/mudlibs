// taoxian.c

#include "herb.h"

void create()
{
	set_name(MAG "桃仙" NOR, ({ "tao xian", "herb_taoxian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 5000);
		set("base_weight", 40);
	}
	setup();
}
