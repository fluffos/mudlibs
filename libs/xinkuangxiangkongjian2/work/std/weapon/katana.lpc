// katana.c

#include <weapon.h>

inherit EQUIP;

varargs void init_katana(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
}

void setup()
{
	::setup();

	if( clonep(this_object()) ) return;

	set("skill_type", "katana");
	if( !query("actions") ) {
		set("actions", (: WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
}
