//ilz
// Cleaned by Cyanide, 11 July 2000

#include <magic.h>
#include <p_spells.h>

#define COST 8

string help();

inherit SPELL;

int invoke_battlefate (string str) {
    object target, shield;
    int flag;

    seteuid(getuid());

    if (!str||str=="me"||str==(string)TP->query("name")) {
	target = TP;
    } else {
	target = present(str, environment(TP));
	if (!target) {
	    write("Couldn't find "+capitalize(str)+" here.\n");
	    return 1;
	}
	if (!living(target)) {
	    write("The target must be alive.\n");
	    return 1;
	}
	flag=1;
    }

    if (present("#BATTLEFATE_SPELL#", target)) {
	if (flag) write(capitalize(subjective(target->query("gender")))+
	      " already has a battlefate spell active!\n");
	if (!flag) write("You already have a battlefate spell active.\n");

	return 0;
    }

    if (!invoke_spell(TP, COST))
	return 0;

    write ("You begin casting battlefate.\n");
    if (flag) 
	say(TPN+" blesses "+target->query("cap_name")+
	  " with a prayer from "+possessive(TP->query("gender"))+
	  "deity.\n");
    else
	say(wrap(TPN+" blesses "+objective(target->query("gender"))+
	    "self with a prayer from "+
	    possessive(TP->query("gender"))+" deity."));

    shield = clone_object(P_OBJ(battlefate_ob));

    if (!shield) {
	write("Your spell fizzles.  Contact Cyanide.\n");
	say(TPN+"'s spell fizzles...\n");
	return 0;
    }

    shield->move(target);
    shield->begin_spell(TP, target);
    return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Battlefate (Priest - Level I - Chaos)

Duration: 30 rounds/lvl			Area of Effect: 1 Target
Cost: 8 TP

	This spell grants a random blessing upon the target.
EndSpellcraft
    );
}
