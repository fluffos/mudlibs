// zzfen.c

#include "herb.h"

void create()
{
	set_name(HIW "珍珠粉" NOR, ({ "zhenzhu fen", "herb_zzfen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("base_unit", "包");
		set("base_value", 10000);
		set("base_weight", 30);
	}
	setup();
}
