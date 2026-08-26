/*
** File: vision.c (Essentially, "Clairvoyance")
** Purpose: 5th level wizard divination spell
**    To to its usefulness in a MUD environment, this spells level has
**    been increased from 3 to 5.
** Cost: 44 SP
** Credits:
**   24 Nov 97  Cyanide created the spell.
*/

#define SYNTAX "Syntax: cast vision at <player>\n"
#define COST 44

#include <commands.h>
#include <magic.h>
#include <m_spells.h>

inherit SPELL;

int cast_vision(string str, int obj) {
    object where, here, target;
    int found;

    if (!str) {
	write(SYNTAX);
	return NO_TARGET;
    } 

    str = lower_case(str);
    target = find_player(str);
    if (target) {
	found = 1;
    } else {
	write("That target cannot be located.\n");
	return SPELL_CAST;
    }

    if (!obj) {
	if (!cast_spell(TP, COST)) return NO_STRENGTH;
	obj = query_caster_level(TP, "wizard");
	write("You begin casting Vision...\n");
	say(TPN+" begins uttering arcane words...\n");
    }

    if (target->query("nondetection")) found = 0;
    if (present("#NONDETECTION#", target)) found = 0;

    if (!found) {
	write("That target cannot be located.\n");
	return SPELL_CAST;
    }

    where = environment(target);
    here = environment(TP);

    if (!where) {
	target->query("cap_name")+" is lost in the Void.\n"+
	"You see only emptiness.\n";
	return SPELL_CAST;
    }

    if (where==here) {
	str = target->query("cap_name")+" is in the same room as you"+
	" are.\n";
    } else {
	str = "An image forms in your mind...\n\nYou see:\n";
	str += CMD_LOOK->look_in_room(where);
    }

    tell_object(target, "You feel as though you're being watched.\n");
    write(str);
    return SPELL_CAST;
}
string spellcraft() {
    return (@EndSpell
Vision (Level IV Wizard Spell - Divination)

Cost: 44 Spell Points

A more powerful version of the locate spell,
this spell describes the room of the target
as if the caster were actually there.
EndSpell
    );
}
/* EOF */
