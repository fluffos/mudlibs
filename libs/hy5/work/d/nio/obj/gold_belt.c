// gold_belt.c 金腰带

#include <armor.h>

inherit WAIST;

void create()
{
	set_name("金腰带", ({ "gold belt", "belt", "yaodai" }));
	set("weight", 600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 5000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
