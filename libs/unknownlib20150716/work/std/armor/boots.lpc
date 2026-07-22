// boots.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	int lvl;
	set("armor_type", TYPE_BOOTS);
	lvl = this_object()->query("level");
	if( lvl<1 )  lvl = 1;
	if( lvl>20 ) lvl = 20;
	delete("armor_prop/armor");
	set("armor_prop/combat_def",lvl+4);
	set("armor_prop/spells_def",lvl+4);
	set("armor_prop/spells_dodge",lvl/3+1);
	set("armor_prop/combat_dodge",lvl/3+1);
}

int is_armor(){ return 1;}