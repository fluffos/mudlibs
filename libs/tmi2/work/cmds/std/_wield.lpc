// _wield.c
// Command to wield weaponry.
// Mobydick@TMI-2, 9/11/92

#include <mudlib.h>

inherit DAEMON ;

int help() ;

int cmd_wield(string str, int silent) {

	object obj, firstwep, secondwep, shield ;
	string name ;
	object wep ;
	int Class, oldattack, newattack ;

	if (!str) {
		return help() ;
	}
	obj = present (str,this_player()) ;
	if (!obj) {
		notify_fail ("You don't possess a "+str+".\n") ;
		return 0 ;
	}
	Class = obj->query("weapon") ;
	if (!Class) {
		notify_fail ("That isn't a weapon.\n") ;
		return 0 ;
	}
	firstwep = this_player()->query("weapon1") ;
	secondwep = this_player()->query("weapon2") ;
	shield = this_player()->query("armor/shield") ;
	if (obj==firstwep || obj==secondwep) {
// He's already wielding it. Tell him so.
		notify_fail ("You are already wielding it!\n") ;
		return 0 ;
	}
	if (firstwep && secondwep) {
		notify_fail ("You are already wielding two weapons.\n") ;
		return 0 ;
	}
	if (firstwep && shield) {
		notify_fail ("You cannot use two weapons and a shield at the same time.\n") ;
		return 0 ;
	}
// Stop the player from attacking for 2 seconds.
	this_player()->block_attack(2) ;
	if (!firstwep && !secondwep) {
		if (shield && (int)obj->query("nosecond")==1) {
			notify_fail ("You cannot use a shield and a two-handed weapon together.\n") ;
			return 0 ;
		}
		if(!silent) {
		write ("You wield "+obj->query("short")+".\n") ;
		say (this_player()->query("cap_name")+" wields "+obj->query("short")+".\n") ;
		}
		this_player()->set("weapon1", obj) ;
		obj->set("wielded",1) ;
		this_player()->set("attack_strength",Class) ;
		str = obj->query("wield_func") ;
		if (str) call_other(obj,str) ;
		return 1 ;
	}
// If we got here, the player is already wielding one weapon.
	if (firstwep->query("nosecond")) {
		notify_fail ("You cannot use a second weapon with "+firstwep->query("short")+".\n") ;
		return 0 ;
	}
	if (obj->query("nosecond")) {
		notify_fail ("You cannot use a second weapon with "+obj->query("short")+".\n") ;
		return 0 ;
	}
	if (!obj->query("second") && !firstwep->query("second")) {
		notify_fail ("You can't use both weapons at the same time.\n");
		return 0 ;
	}
	oldattack = (int)firstwep->query("weapon") ;
	if ((int)obj->query("second")) Class=Class/2 ; else oldattack=oldattack/2 ;
	if(!silent)
	write ("You wield "+obj->query("short")+".\n") ;
	if ((int)obj->query("second")) {
		this_player()->set("weapon2", obj) ;
	} else {
		this_player()->set("weapon2", firstwep) ;
		this_player()->set("weapon1", obj) ;
	}
	this_player()->set("attack_strength",Class+oldattack) ;
	str = obj->query("wield_func") ;
       if (str) call_other(obj,str) ;
	obj->set ("wielded", 1) ;
	if(!silent)
	say (this_player()->query("cap_name")+" wields "+obj->query("short")+".\n") ;
	return 1 ;
}

int help() {
	write (
"Usage: wield <weapon name>\n\n" +
"The wield command allows you to wield weapons. Typing 'wield sword' lets\n"+
"you use a sword, if you have one. You can wield up to two weapons at once.\n"+
"However, the second weapon must be a small weapon such as a dagger or hand\n"+
"axe, and you cannot use a second weapon with a shield or two-handed weapon.\n"+
"If you are using two weapons, most of your attacks, but not all, will be\n"+
"made using the larger weapon. Wielding a second weapon will increase your\n"+
"chance to hit with either of your two weapons. However, if one of your\n"+
"weapons is much better than the other, you may be better off not using\n"+
"the second weapon.\n"+
"\nSee also: equip.\n") ;
	return 1 ;
}

