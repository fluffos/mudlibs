/*
** FILE:        armor.c
** PURPOSE:     Protection - 1st level mage conjuration spell.
** COST:        10 SP
** EFFECTS:     Gives the caster up to 6 magical points of armor.
** DURATION:    30 seconds/level.
** CREDITS: 
**    21 Jul 97  Cyanide wrote the spell.
*/               

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 10

inherit SPELL;

int cast_armor (string str, int obj) {
    object armor, firstarmor;
    int flag;

    seteuid(getuid());

    if (!obj) {
	if (!cast_spell(TP, COST)) return NO_STRENGTH;
	obj = query_caster_level(TP, "wizard");
    }

    // if ((environment(TP)->local_spell_effects(({"conjuration"})))==-1)
    //    return 1;

    firstarmor = present("#ARMOR_OB#", TP);
    if (firstarmor) {
	write("You re-cast armor upon yourself.\n");
	firstarmor->remove();
	flag = 1;
    }

    armor = clone_object(M_OBJ(armor_ob));
    if (!armor) {
	write("Your spell fails.  Notify Cyanide.\n");
	return 0;
    }
    flag = 0;

    write("You conjure into existance a protective mantle of force.\n");
    say(wrap(TPN+" closes "+POSS+" eyes for a moment, and is shrouded in"+
	" a ghostly armor.\n"));

    armor->move(TP);
    armor->begin_spell(TP, obj, flag);

    return 1;
}
string spellcraft() {
    return (@EndSpell
Armor (Level I Wizard Spell - Conjuration)

Cost: 10 Spell Points

This spell summons armor around the body
of the caster, providing for defense.
EndSpell
    );
}

/* EOF */
