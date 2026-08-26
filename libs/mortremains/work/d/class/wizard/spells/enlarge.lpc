/*
** FILE:        enlarge.c
** PURPOSE:     1st level alteration spell.
** COST:        9 SP
** EFFECTS:     Increases subject's size by 10% per caster level. All 
**              combat damage increases a like amount.
** DURATION:    30 seconds/level.
** CREDITS: 
**    21 Jul 97  Cyanide wrote the spell.
**     7 Mar 00  Cyanide made so you could only cast this on yourself
**                 or your followers.
*/               

#include <move.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 9

inherit SPELL;

int cast_enlarge (string str) {
    object targ, ob;

    seteuid(getuid());

    if (!str) str = TP->query("name");

    targ = present(str, environment(TP));
    if (!targ) {
	write("That isn't here!\n");
	return 1;
    }

    if (!living(targ)) {
	write("That spell works better when cast on something living.\n");
	return 0;
    }

    if (userp(targ)) {
	ob = targ;
    } else {
	ob = targ->query("summoner");
    }

    if ((environment(TP)->local_spell_effects(({"abjuration"})))==-1)
	return 1;

    if (ob != TP) {
	write("You can only cast that on yourself or your followers.\n");
	return 0;
    }

    if (present("#ENLARGE_OB#", targ)) {
	write("That target has already been magically enlarged.\n");
	return 0;
    }

    if (!TP->cast_spell(COST)) { 
	write("You cannot muster the energies to cast that spell.\n");
	return 0;
    }

    write("You cast enlarge at ");
    say (TPN+" casts enlarge at ");
    if (targ == TP) {
	write("yourself.\n");
	say(objective(TP->query("gender"))+"self.\n");
    } else {
	write(targ->query("cap_name")+".\n");
	say(targ->query("cap_name")+".\n", targ);
	tell_object(targ, "you.\n");
    }

    ob = clone_object(M_OBJ(enlarge_ob));
    if (!ob) {
	write("Your spell fails.  Notify Cyanide.\n");
	return 0;
    }

    if (ob->move(targ) != MOVE_OK) {
	write("Error in enlarge_ob moving!\n"+
	  "Notify Cyanide!\n");
	return 1;
    }

    ob->begin_spell(query_caster_level(TP, "wizard"));
    return 1;
}
string spellcraft() {
    return (@EndSpell
Dispel magic (Level III Wizard Spell - Alteration)

Cost: 9 Spell Points

This spell causes instant growth of a creature,
increasing both size and weight. This also makes
the target more powerfull physically. 
EndSpell
    );
}
