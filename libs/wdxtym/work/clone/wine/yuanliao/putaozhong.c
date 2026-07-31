// dangui.c

#include "herb.h"

void create()
{
	set_name(HIR "葡萄藤" NOR, ({ "putao zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是酿酒材料的种苗。\n");
		set("base_unit", "根");
		set("base_value", 1000);
		set("base_weight", 70);
		set("level", 25);
		set("end","/clone/wine/yuanliao/putao");
	}
	setup();
}
