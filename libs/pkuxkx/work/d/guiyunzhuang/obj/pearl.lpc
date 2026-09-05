// pearl.c 金项链

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("珍珠手镯", ({"pearl"}));
	set_weight( 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 6000);
		set("material", "pearl");
		set("armor_prop/armor", 2);
	}
	setup();
}	
