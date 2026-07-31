// chuanwu.c

#include "herb.h"

void create()
{
	set_name(WHT "川乌" NOR, ({ "chuanwu", "herb_chuanwu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 200);
		set("base_weight", 50);
	}
	setup();
}
