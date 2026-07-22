// hammer.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_hand(int damage, int flag)
{
	set("changed",1);
	if( damage>8 )
		set("weapon_prop/spells_damage", damage/8);
	set("weapon_prop/combat_damage", damage/3*2);	
    	set("flag", 1);
    	set("skill_type", "unarmed");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

int is_weapon(){ return 1;}