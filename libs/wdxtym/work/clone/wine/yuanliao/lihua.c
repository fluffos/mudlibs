// dangui.c

#include "herb.h"

void create()
{
	set_name(HIW "梨花" NOR, ({ "li hua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是酿酒材料。\n");
		set("base_unit", "筐");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",225);	
		set("wine","/clone/wine/lihuajiu");
	}
	setup();
}
