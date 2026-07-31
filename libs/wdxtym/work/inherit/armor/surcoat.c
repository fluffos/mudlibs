// surcoat.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if (! clonep(this_object()))
	set("armor_type", TYPE_SURCOAT);
set("armor_buwei", "ÍâÌ×");
 if( !query("armor_apply/dodge") &&	 weight() > 3000 )
	set("armor_prop/dodge", - weight() / 3000 );

	::setup();
}
