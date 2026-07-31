// xsword.c

#include <weapon.h>
#include <music.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

inherit MI_XIAO;

varargs void init_xsword(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage * 90 / 100);
	set("flag", (int)flag | EDGED);
	set("skill_type", "sword");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
}

void init()
{
	add_action("play_xiao", "play");
}
