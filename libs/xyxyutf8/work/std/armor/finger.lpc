// finger.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	int lvl;
	set("armor_type", TYPE_FINGER);
	delete("armor_prop/armor");
	lvl = this_object()->query("level");
	if( lvl<1 ) lvl = 1;
	if( lvl>20 ) lvl = 20;
	set("armor_prop/spells_damage",1+lvl);
	set("armor_prop/combat_damage",2+lvl);
}

int is_armor(){ return 1;}