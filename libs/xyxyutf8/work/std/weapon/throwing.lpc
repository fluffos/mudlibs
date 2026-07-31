// cracked by vikee 2/09/2002   vikee@263.net
// throwing.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

varargs void init_throwing(int damage, int flag)
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
	set("skill_type", "throwing");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :));
		set("verbs", ({ "throw" }) );
	}
}

int is_weapon(){ return 1;}