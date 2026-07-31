// wulingzhi.c

#include "herb.h"

void create()
{
	set_name(MAG "五灵脂" NOR, ({ "wu lingzhi", "herb_wulingzhi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "块");
		set("base_value", 5000);
		set("base_weight", 100);
	}
	setup();
}
