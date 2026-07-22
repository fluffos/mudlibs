// dagger.c

#include <weapon.h>

inherit EQUIP;

varargs void init_stabber(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag | EDGED | SECONDARY );
}

void setup()
{
	::setup();

	if( clonep(this_object()) ) return;

	set("skill_type", "stabber");
	if( !query("actions") ) {
		set("actions", (: WEAPON_D, "query_action" :) );
                set("verbs", ({ "thrust", "pierce" }));
	}
}
