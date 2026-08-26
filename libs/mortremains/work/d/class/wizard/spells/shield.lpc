/*
** File: shield.c
** Purpose: 1st level mage alteration spell.
** Cost 9 spell points
** Duration: 50 sec/level
** Credits:
**  28 Jul 97  Cyanide wrote the file.
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 9

string help();

int cast_shield () {
  object shield;

  seteuid(getuid());

  if (present("#SHIELD_SPELL#", TP)) {
    write("You already have a shield active!\n");
    return 0;
  }

  if (!TP->cast_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting shield.\n");

  say ("Begins muttering arcane verses...\n");

  shield = clone_object(M_OBJ(shield_ob.c));
  if (!shield) {
    write("Your spell fizzles.  Contact Cyanide.\n");
    say(TPN+"'s spell fizzles...\n");
    return 0;
  }

  shield->move(TP);
  shield->begin_spell(TP);
  return 1;
}

string spellcraft() {
    return (@EndSpell
Shield (Level I Wizard Spell - Alteration)

Cost: 9 Spell Points

This spell summons a defensive shield for
the caster, providing for defense, and stopping
force damage.
EndSpell
    );
}

/* EOF */