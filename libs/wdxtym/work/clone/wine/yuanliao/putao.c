// dangui.c

#include "herb.h"

void create()
{
	set_name(HIM "ÆÏÌÑ" NOR, ({ "pu tao" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÄğ¾Æ²ÄÁÏ¡£\n");
		set("base_unit", "¿ğ");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",75);	
		set("wine","/clone/wine/putaojiu");
	}
	setup();
}
