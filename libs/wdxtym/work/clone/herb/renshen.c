// renshen.c

#include "herb.h"

void create()
{
	set_name(HIW "人参" NOR, ({ "renshen", "herb_renshen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "根");
		set("base_value", 10000);
		set("base_weight", 90);
	}
	setup();
}
