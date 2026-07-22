// neck.c

#include <armor.h>
inherit EQUIP;

void setup()
{
	int lvl;
	set("armor_type", TYPE_NECK);
	lvl = this_object()->query("level");
	if( lvl<1 ) lvl = 1;
	if( lvl>10 ) lvl = 10;
	delete("armor_prop/armor");
	set("armor_prop/spells_succ",lvl);
	set("armor_prop/combat_succ",lvl);
	set("armor_prop/spells_dodge",lvl);
	set("armor_prop/spells_dodge",lvl);
}

int is_armor(){ return 1;}