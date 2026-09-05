
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("薄底快靴", ({ "baodi kuaixue", "xue" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "一双薄底快靴");
		set("value", 10000);
		set("material", "boots");
		set("armor_prop/dodge", 2);
		//set("shaolin",1);
	}
	setup();
}
