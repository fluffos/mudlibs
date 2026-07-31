// gold_ribbon.c 束发金带

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("束发金带", ({ "gold ribbon", "ribon", "dai" }));
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 2000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
