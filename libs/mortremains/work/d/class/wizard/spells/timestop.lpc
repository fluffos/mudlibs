/*
** File: timestop.c (Time Stop)
** Purpose: A level 9 alteration spell (M9)
** Effects: Causes all action within the room to stop.
**    No attacks are made, no spells are cast. Nothing.
**    The caster and wizards are immune to its effects.
** Cost: 120 SP (Ouch)
** Credits:
**   22 Nov 97  Cyanide created the spell.
*/

#define COST 120

#include <m_spells.h>
#include <mudlib.h>
#include <magic.h>

inherit SPELL;

int cast_timestop(string str, int obj) {
    object ob;
    seteuid(getuid());

    write("Sorry - this spell is temporarily out of service.\n"+
      "We apologize for any inconvenience this may cause.\n"+
      "                 -Cyanide\n");
    return 1;


    if (!obj) {
	if (!cast_spell(TP, COST)) return NO_STRENGTH;
	TP->set("power_delay", 1);

	write("You begin casting Time Stop...\n");
	say(TPN+" begins uttering arcane words...\n");

	tell_room(environment(TP), wrap("Time comes to a halt."), ({ TP }) );
	write("Everyone around you is stuck between seconds...\n");
	obj = query_caster_level(TP, "wizard");
    }

    ob = clone_object(M_OBJ(timestop_ob.c));
    ob->activate(TP, obj);
    ob->move(environment(this_player()));

    return SPELL_CAST;
}
string spellcraft() {
    return (@EndSpell
Time Stop (Level IX Wizard Spell - Alteration)

Cost: 120 Spell Points

This spell stops time around the caster, allowing
him to act while others are caught in stasis.
EndSpell
    );
}
/* EOF */
