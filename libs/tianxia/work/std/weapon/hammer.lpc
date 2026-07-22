// hammer.c
// Modified by Find.

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

int is_weapon() {return 1;}

varargs void init_hammer(int damage, int flag)
{
	if(!damage)
	{
		if( clonep() )
			set("weapon_prop/damage", WEAPON_D->query_weapon_base_damage(this_object()));
	}
	else
		set("weapon_prop/damage", damage);

	if( clonep(this_object()) ) return;

	set("flag", flag );
	set("skill_type", "hammer");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
	if(!query("value"))
		set("value", WEAPON_D->query_weapon_base_value(this_object()));
}

