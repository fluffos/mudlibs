/*
** FILE:        invis.c
** PURPOSE:     2nd level illusion spell.
** COST:        15 SP
** EFFECTS:     Renders the subject invisible to other mortals.
** DURATION:    Until attacks.
** CREDITS: 
**    21 Jul 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 15

inherit SPELL;

int cast_invisibility (string str, int obj) {
    object targ, ob;

    seteuid(getuid());

    str = TP->query("name");
    //if (!str) str = TP->query("name");

    targ = present(str, environment(TP));
    if (!targ) {
	write("That isn't here!\n");
	return 0;
    }

    if (!living(targ)) {
	write("That spell works better when cast on something living.\n");
	return 0;
    }

    if ((environment(TP)->local_spell_effects(({"illusion"})))==-1)
	return 0;

    if (targ->query("invisible")) {
	write("That target is already invisible.\n");
	return 0;
    }

    if (wizardp(targ)) {
	if (targ==this_player())
	    write("Use \"invis players\" command instead.\n");
	else
	    write("That player is a wizard, and does not need yout spell!\n");
	return 0;
    }

    if (!cast_spell(TP, COST)) {
	return 0;
    }

    write("You cast invisibility at ");
    say (TPN+" casts invisibility at ");
    if (targ == TP) {
	write("yourself.\n");
	say(objective(TP->query("gender"))+"self.\n");
    } else {
	write(targ->query("cap_name")+".\n");
	say(targ->query("cap_name")+".\n", targ);
	tell_object(targ, "you.\n");
    }

    ob = clone_object(M_OBJ(invis_ob));
    if (!ob) {
	write("Your spell fails.  Notify Cyanide.\n");
	return 0;
    }

    ob->move(targ);

    // If this is cast by an object, we use the obj variable as the object's
    // casting level - else, we use query_caster_level().

    if (!obj) obj = TP->query_caster_level("wizard");
    ob->begin_spell(obj);
    return 1;
}
string spellcraft() {
    return (@EndCraft
Invisibility (Wizard  Level II  Illusion/Phantasm)

Area of Effect: Caster		Saving Throw: None
Cost: 15 SP
Duration: Until attack

    This spell grants the caster invisibility to
other mortals until the caster attacks.
EndCraft
    );
}
