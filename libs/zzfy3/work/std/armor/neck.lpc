// neck.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;

	set("armor_type", TYPE_NECK);
	if( !query("armor_apply/dodge")
	&&	weight() > 300000 )
		set("armor_prop/dodge", - weight() / 300000 );
}
