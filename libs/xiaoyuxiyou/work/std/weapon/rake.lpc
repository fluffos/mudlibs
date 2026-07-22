// cracked by vikee 2/09/2002   vikee@263.net
// blade.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_rake(int damage, int flag)
{
	set("changed",1);
	if( damage>5 )
		set("weapon_prop/spells_damage", damage/5);
	set("weapon_prop/combat_damage", damage);	

	set("flag", (int)flag | EDGED);
	set("skill_type", "rake");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "rake", "strike", "bash" }) );
	}
}

int is_weapon(){ return 1;}