// cracked by vikee 2/09/2002   vikee@263.net
// archery.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

varargs void init_archery(int damage, int flag)
{
	set("changed",1);
	if( damage>5 )
		set("weapon_prop/spells_damage", damage/5);
	set("weapon_prop/combat_damage", damage);	

	set("flag", flag); 
}

void setup()
{
	// ::setup();
	seteuid(getuid());
	set("skill_type", "sword");
	set("apply/skill_type", "archery");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :));
		set("verbs", ({ "slash", "slice", "thrust", "pierce" }) );
	}
    	if( !query("apply/actions") ) {
	   set("apply/actions", (: call_other, WEAPON_D, "query_apply_action" :) );
	   set("apply/verbs", ({ "shoot" }) );
    	}

}

int is_weapon(){ return 1;}