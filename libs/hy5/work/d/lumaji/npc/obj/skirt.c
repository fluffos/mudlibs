// skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("布裙", ({ "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一条普通的布裙。\n");
		set("unit", "条");
		set("value", 30);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	setup();
}