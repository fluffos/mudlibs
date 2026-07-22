// whip.c

#include <weapon.h>

inherit EQUIP;

varargs void init_whip(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag );
}

void setup()
{
	::setup();

	if( clonep(this_object()) ) return;

	set("skill_type", "whip");
	if( !query("actions") ) {
		set("actions", (: WEAPON_D, "query_action" :) );
		set("verbs", ({ "whip" }) );
	}
}
