// dangui.c

#include "herb.h"

void create()
{
	set_name(WHT "糯米种" NOR, ({ "nuomi zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是酿酒材料的种子。\n");
		set("base_unit", "捧");
		set("base_value", 2000);
		set("base_weight", 70);
		set("level", 100);
		set("end","/clone/wine/yuanliao/nuomi");
	}
	setup();
}
