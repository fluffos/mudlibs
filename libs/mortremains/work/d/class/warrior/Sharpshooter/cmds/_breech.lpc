// _breech.c - Written by Chronos to replace the old one.
// This one actually does something. ;)
#include <mudlib.h>
#include "checkob.h"

inherit DAEMON;

int cmd_breech(string str) {
    object weapon, spell_ob ;
    string wepstr ;
    int lvl, bonus ;
    if (!checkob(TP)) return 1;
    if ((int)TP->query("hit_points") < (int)TP->query("max_hp")) {
	write("You're life energy is too low to use this ability.\n") ;
	return 1;
    }

    if (!str) {
	weapon = TP->query("weapon1");
	if (!weapon) weapon = TP->query("weapon2");
    } else  switch(str) {
    case "left" : weapon=TP->query("weapon2") ;
	break ;
    case "right" : weapon=TP->query("weapon1") ;
	break ;
    default: write("It's either right or left, dumbass.\n") ;
	return 1;
	break ;
    }
    if  (!weapon) {
	write("You must have your weapons wielded.\n");
	return 1;
    }
    if (weapon->query("breeched")) {
	write("This weapon has already been breeched.\n") ;
	return 1;
    }
    lvl = this_player()->query("level");
    switch(lvl) {
    case 1..9:
	write("You do not have that ability yet.\n");
	return 1;
	break ;
    case 10..19:
	bonus = 1 ;
	break ;
    case 20..29:
	bonus = 2;
	break ;
    case 30..39:
	bonus = 3 ;
	break ;
    default:
	bonus = 4;
	break ;
    }
    weapon->set_bonus(bonus, bonus*2, bonus) ;
    weapon->add("light", 1) ;
    weapon->set("breeched", 1) ;
    wepstr=weapon->query("name") ;
    say(TPN+" holds "+possessive(TP->query("gender"))+" "+wepstr+
      " before "+
      objective(TP->query("gender"))+"self and concentrates..\n") ;
    say(capitalize(wepstr)+" begins to glow with an unearthly power.\n") ;
    write(wrap("You pour your life force into the weapon, imbuing it with your power.  "+
	capitalize(wepstr)+" begins to glow and you begin to feel faint..")) ;
    TP->set("hit_points", 1);
    write("You drop to one knee..\n") ;
    say(TPN+" drops to one knee in sheer exhaustion.\n") ;
    spell_ob = clone_object("/d/class/warrior/Sharpshooter/obj/breech_ob") ;
    spell_ob->move(TP) ;
    spell_ob->activate(weapon, lvl, bonus) ;
    return 1;
}

