// blade.c

#include <weapon.h>

// inherit COMBINED_ITEM;
//add by musix 97.7.6

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_blade(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "blade");
	if( !query("actions") ) {
		set("actions", (: WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
	}
}

