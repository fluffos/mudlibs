// qin.c
// edit by god

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_qin(int damage, int flag)
{
	set("changed",1);
	if( damage>5 )
		set("weapon_prop/spells_damage", damage/5);
	set("weapon_prop/combat_damage", damage);	
	set("flag", (int)flag | EDGED);
        set("skill_type", "art");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust", "pierce" }) );
	}
}

int is_weapon(){ return 1;}