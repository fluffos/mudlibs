// shanjia

#include "herb.h"

void create()
{
	set_name(GRN "山甲" NOR, ({ "shan jia", "herb_shanjia" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "片");
		set("base_value", 2000);
		set("base_weight", 60);
	}
	setup();
}
