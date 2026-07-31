// hupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("虎皮围裙", ({ "hupi skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一条由虎皮做成的围裙。\n");
		set("unit", "条");
		set("value", 2000);
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	setup();
}