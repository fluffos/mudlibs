// sword.c

#include <weapon.h>
#include <armor.h>

//#ifdef AS_FEATURE
//#include <dbase.h>
//#else
inherit HEAD;
//#endif

void setup()
{
	if( clonep(this_object()) ) return;
	set("armor_type", TYPE_HEAD);
}

varargs void init_sword(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("skill_type", "sword");
	if( !query("actions") ) {
		set("actions", (: WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
}

