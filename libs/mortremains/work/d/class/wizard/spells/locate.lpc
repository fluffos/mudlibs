/*
** File: locate.c (Locate Creature)
** Purpose: 4th level wizard divination spell
** Cost: 30 SP
** Credits:
**   24 Nov 97  Cyanide created the spell.
*/

#define SYNTAX "Syntax: cast locate at <target>\n"
#define COST 30

#include <magic.h>

inherit SPELL;

int cast_locate(string str, int obj) {
    object where, here, target;
    int found, lvl;

    if (!str) {
	write(SYNTAX);
	return NO_TARGET;
    } 

    str = lower_case(str);
    target = find_player(str);
    if (!target) {
	target = TP;
	found = 1;
    }

    if (!obj) {
	if (!cast_spell(TP, COST)) return NO_STRENGTH;
	lvl = query_caster_level(TP, "wizard");
	obj = lvl;
	write("You begin casting Locate Creature...\n");
	say(TPN+" begins uttering arcane words...\n");
    } else {
	lvl = obj;
    }

    found = 1;
    where = environment(target);
    here = environment(TP);

    if (wizardp(target)) found = 0;
    if (target->query("nondetection")) found = 0;
    if (present("#NONDETECTION#", target)) found = 0;

    if (!where) {
	write(target->query("cap_name")+" is lost in the Void.\n"); 
	return SPELL_CAST;
    }

    if (!found) {
	write("That target cannot be located.\n");
	return SPELL_CAST;
    }

    if (where==here) {
	str = target->query("cap_name")+" is in the same room as you are!\n";
    } else {
	str = where->query("short");
	if (!str) str = "a nameless room";
	str = target->query("cap_name")+" is in " + str + ".\n";
    }

    tell_object(target, wrap("You feel a strange tingling at "+
	"the back of your spine.\n"));
    write(str);
    return SPELL_CAST;
}
string spellcraft() {
   return (@EndCraft
Locate (Wizard  Level IV  Divination)

Area of Effect: Other Player		Saving Throw: None
Cost: 30 SP

    This spell allows the caster to locate the room the
target is currently in. Not directions to the room, just
a geral description of the target's surroundings.
EndCraft
   );
}