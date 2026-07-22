// cracked by vikee 2/09/2002   vikee@263.net
// bow.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_bow(int damage, int flag)
{
	set("changed",1);
	if( damage>5 )
		set("weapon_prop/spells_damage", damage/5);
	set("weapon_prop/combat_damage", damage);	

	set("flag", flag|SECONDARY );
	set("skill_type", "blade");
	set("apply/skill_type", "archery");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack", "chop" }) );
	}
}

int is_weapon(){ return 1;}