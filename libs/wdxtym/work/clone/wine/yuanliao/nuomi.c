// dangui.c

#include "herb.h"

void create()
{
	set_name(WHT "糯米" NOR, ({ "nuo mi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是酿酒材料。\n");
		set("base_unit", "斗");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",175);	
		set("wine","/clone/wine/zhuangyuanhong");
	}
	setup();
}
