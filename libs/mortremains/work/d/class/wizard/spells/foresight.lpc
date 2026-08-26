/*
** FILE:        foresight.c
** PURPOSE:     3rd level divination spell.
** COST:        90 SP
** EFFECTS:     Gives caster the ability to do a particular action before
**              an attack takes place.
** DURATION:    Until dispelled
** CREDITS: 
**    09 Nov 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 90

inherit SPELL;

int cast_foresight(string str, int obj) {
    object ob;

    seteuid(getuid());

    if ((environment(TP)->local_spell_effects(({"divination"})))==-1)
	return 1;

    if (present("#FORESIGHT#", TP)) {
	write("You already are benefitting from foresight.\n");
	return 0;
    }

    if (!obj) {
	if (!cast_spell(TP, COST)) return 0;

	write("You attempt to cast Foresight.\n");
	say(TPN+" mumbles something in an arcane language.\n");
	obj = query_caster_level(TP, "wizard");
    }

    ob = clone_object(M_OBJ(foresight_ob));
    if (!ob) {
	write("Your spell fails.  Notify Cyanide.\n");
	return 0;
    }

    ob->move(TP);
    ob->begin_spell(TP, obj);
    return 1;
}

/* EOF */
