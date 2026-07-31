// xiongdan.c

#include "herb.h"

void create()
{
	set_name(HIR "熊胆" NOR, ({ "xiongdan", "herb_xiongdan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "个");
		set("base_value", 10000);
		set("base_weight", 70);
	}
	setup();
}
