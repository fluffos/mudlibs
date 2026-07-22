// head.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	int lv;
	set("armor_type", TYPE_HEAD);
	delete("armor_type/armor");
	lv = this_object()->query("level");
	if( lv<1 ) lv = 1;
	if( lv>10 ) lv = 10;
	set("armor_prop/combat_def",lv);
	set("armor_prop/spells_def",lv);
}

int is_armor(){ return 1;}