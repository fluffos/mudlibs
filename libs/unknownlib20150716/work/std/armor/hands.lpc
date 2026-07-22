// hands.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	int lv;
	set("armor_type", TYPE_HANDS);
	delete("armor_type/armor");
	lv = this_object()->query("level");
	if( lv<1 ) lv = 1;
	if( lv>5 ) lv = 5;
	set("armor_prop/combat_parry",lv);
}

int is_armor(){ return 1;}