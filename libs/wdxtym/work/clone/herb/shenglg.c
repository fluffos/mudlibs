// shenglg.c

#include "herb.h"

void create()
{
	set_name(CYN "生龙骨" NOR, ({ "shenglong gu", "herb_slg" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 4000);
		set("base_weight", 120);
	}
	setup();
}
