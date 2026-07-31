// dangui.c

#include "herb.h"

void create()
{
	set_name(HIR "高粱" NOR, ({ "gao liang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是酿酒材料。\n");
		set("base_unit", "斗");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",25);	
		set("wine","/clone/wine/gaoliangjiu");
	}
	setup();
}
