// sword.c
// Modified by Find.

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

int is_weapon() {return 1;}

varargs void init_sword(int damage, int flag)
{
	if(!damage)
	{
		if( clonep() )
			set("weapon_prop/damage", WEAPON_D->query_weapon_base_damage(this_object()));
	}
	else
		set("weapon_prop/damage", damage);

	if( clonep(this_object()) ) return;

	set("flag", (int)flag | EDGED);
	set("skill_type", "sword");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
	if(!query("value"))
		set("value", WEAPON_D->query_weapon_base_value(this_object()));
}

