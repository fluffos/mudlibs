// shedan.c

#include "herb.h"

void create()
{
	set_name(HIG "蛇胆" NOR, ({ "shedan", "herb_shedan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "个");
		set("base_value", 6000);
		set("base_weight", 30);
	}
	setup();
}

