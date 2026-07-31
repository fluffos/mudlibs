// yjhua.c

#include "herb.h"

void create()
{
	set_name(YEL "洋金花" NOR, ({ "yang jinhua", "herb_yjhua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "朵");
		set("base_value", 400);
		set("base_weight", 20);
	}
	setup();
}
