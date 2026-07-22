// waist.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	int lvl;
	set("armor_type", TYPE_WAIST);
	delete("armor_prop/armor");
	lvl = this_object()->query("level");
	if( lvl<1 ) lvl = 1;
	if( lvl>20 ) lvl =20;
	set("armor_prop/max_kee",lvl*10);
}

int is_armor(){ return 1;}