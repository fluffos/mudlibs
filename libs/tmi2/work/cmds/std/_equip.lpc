// _equip.c
// Command to equip armor
// Mobydick@TMI-2, 9/17/92

#include <mudlib.h>

inherit DAEMON ;

int cmd_equip(string str, int silent) {

	mapping armor ;
	object obj, fwep, swep ;
	string type ;
	int Class ;

	notify_fail("Equip what?\n");
	if(!str || str == "")  return 0;
 
	obj = present (str,this_player()) ;
	if (!obj) {
		notify_fail ("You don't possess a "+str+".\n") ;
		return 0 ;
	}
	if (undefinedp(obj->query("armor"))) {
		notify_fail ("That isn't armor.\n") ;
		return 0 ;
	}
	Class = obj->query("armor") ;
	if (obj->query("equipped")) {
// He's already equipping it. Tell him so.
		notify_fail ("You are already equipping it!\n") ;
		return 0 ;
	}
// If this is a shield, check his weapons and make sure he has a free arm.
	type = obj->query("type") ;
	if (type=="shield") {
		fwep = this_player()->query("weapon1") ;
		swep = this_player()->query("weapon2") ;
		if (swep) {
			notify_fail ("You can't use the shield and two weapons at the same time.\n") ;
			return 0 ;
		}
		if (fwep && (int)fwep->query("nosecond")==1) {
			notify_fail ("You must have a free arm to use the shield.\n") ;
			return 0 ;
		}
	}
	armor = this_player()->query("armor") ;
	if (armor && member_array(type, keys(armor))!=-1) {
		notify_fail ("You are already wearing armor of type "+type+".\n");
		return 0 ;
	}
	this_player()->block_attack(6) ;
 
	if(!silent) {
	write ("You equip "+obj->query("short")+".\n") ;
	say (this_player()->query("cap_name")+" equips "+obj->query("short")+".\n") ;
	}
	this_player()->set("armor/"+type,obj->query("armor")) ;
	obj->set("equipped",1) ;
	str = obj->query("equip_func");
	if(str)  call_other(obj, str);
	this_player()->calc_armor_class() ;
	return 1 ;
}

string help() {
	return("Syntax: equip <armor>\n\n"+
"The equip command lets you wear armor. There are several types of armor\n"+
"(suit, shield, helmet, etc) and you may equip one of each type. Equipping\n"+
"a shield will prevent you from using two weapons, or a two-handed weapon.\n"+
"\nSee also: wield\n") ;
}
