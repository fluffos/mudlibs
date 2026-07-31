// wrists.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;
	if( query("armor_prop/armor") > PROP_WRISTS )
	  set("armor_prop/armor", PROP_WRISTS);
	set("armor_type", TYPE_WRISTS);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}
