#include "herb.h"

void create()
{
	set_name(HIY "ÐÛ»Æ" NOR, ({ "xiong huang", "herb_xionghuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("base_unit", "¿é");
		set("base_value", 500);
		set("base_weight", 30);
	}
	setup();
}

