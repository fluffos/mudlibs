

#include <armor.h>

inherit NECK;

void create()
{
	set_name("金戒指", ({ "shou zhuo", "zhuo"}));
	set_weight( 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 10000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
