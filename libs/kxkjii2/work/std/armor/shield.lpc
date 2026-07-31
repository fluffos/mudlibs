// shield.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;
	if( query("armor_prop/armor") > PROP_SHIELD )
	  set("armor_prop/armor", PROP_SHIELD);
	set("armor_type", TYPE_SHIELD);
	if( !query("armor_apply/dodge") && weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}
