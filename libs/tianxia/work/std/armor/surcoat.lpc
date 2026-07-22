// surcoat.c

#include <armor.h>

inherit EQUIP;

/* by Find.*/
nomask int is_armor() {return 1;}

void setup()
{
	if( clonep(this_object()) ) return;

	set("armor_type", TYPE_SURCOAT);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}
