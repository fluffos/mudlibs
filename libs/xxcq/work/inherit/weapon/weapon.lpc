
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

// axe.c
varargs void init_axe(int damage, int flag)
{
	
	set("weapon_prop/damage", damage);
	set("flag", flag);
	set("skill_type", "axe");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "chopaxe",  "hackaxe", "axe" }) );
	}
}


// blade.c
varargs void init_blade(int damage, int flag)
{
	
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "blade");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
	}
}

// club.c
varargs void init_club(int damage, int flag)
{
	
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG );
	set("skill_type", "club");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// dagger.c

varargs void init_dagger(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", flag | EDGED | SECONDARY );
	set("skill_type", "sword");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "slice", "pierce", "thrust" }) );
	}
}

// fork.c

varargs void init_fork(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | POINTED);
	set("skill_type", "fork");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "thrust" }) );
	}
}

// hammer.c

varargs void init_hammer(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "hammer");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// staff.c

varargs void init_staff(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG );
	set("skill_type", "staff");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// sword.c


varargs void init_sword(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "sword");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
}

// whip.c

varargs void init_whip(int damage, int flag)
{
	

	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "whip");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "whip" }) );
	}
}

varargs void init_hamulus(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag);
	set("skill_type", "hamulus");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "thrush", "pierce" }) );
	}
}

varargs void init_spear(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag);
	set("skill_type", "spear");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "thrust", "pierce", "impale" }) );
	}
}

varargs void init_stick(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag);
	set("skill_type", "stick");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

varargs void init_throwing(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag);
	set("skill_type", "throwing");
	if( !query("actions") ) {
		set("actions", (: call_other,WEAPON_D, "query_action" :));
		set("verbs", ({ "throw" }) );
	}
}