// boot.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "狼皮雪靴", ({ "wolveskin boots", "boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("value", 2800);
		set("material", "fur");
		set("armor_prop/armor", 5);
	}
	setup();
}
