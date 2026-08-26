/*
** File:  aid.c
** Purpose: 1st-level priest spell, "aid".
** Duration 30 seconds/level.
** Cost:  12 SP
** Credits:
**   28 Jul 97  Cyanide@Nightfall's Keep write the file.
**   ?? ??? ??  Ilzarion used it to make Aid.
**   16 Dec 98  Cyanide repaired.
*/


#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 12

string help();

inherit SPELL;

int invoke_aid (string str) {
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
    if (present("#AID_SPELL#", target)) {
	if (flag) write("They have an aid spell active!\n");
	if (!flag) write("You have an aid spell active!\n");

	return 0;
    }

    if (!invoke_spell(TP, COST)) return 0;

    write ("You begin casting Aid.\n");
    if (flag) say(wrap(TPN+" aids "+target->query("cap_name")+
	    " with a prayer from "+possessive(TP->query("gender"))+
	    " god.\n"));

    shield = clone_object("/d/class/priest/obj/aid_ob");

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
Aid (Priest - Level II - Necromantic)

Duration: 30 rounds/lvl			Area of Effect: 1 Target
Cost: 12 TP

	This spell grants bonus hit points and a blessing
upon the target.
EndSpellcraft
    );
}
