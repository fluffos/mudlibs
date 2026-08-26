/*
** FILE:        minorglobe.c
** PURPOSE:     4st level abjuration spell.
** COST:        30 SP
** EFFECTS:     Blocks all spells of about 3rd level and below.
** DURATION:    30 seconds/level.
** CREDITS: 
**    21 Jul 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 30

int cast_minorglobe(string str, int obj) {
  object ob;

  seteuid(getuid());

  if (!living(TP)) {
    write("That spell works better when cast on something living.\n");
    return 0;
  }

  if ((environment(TP)->local_spell_effects(({"abjuration"})))==-1)
    return 1;

  if (present("#GLOBE#", TP)) {
    write("You are already protected by a magical globe.\n");
    return 0;
  }

  if (!obj) {
  if (!TP->cast_spell(COST)) { 
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write("You attempt to cast Minor Globe of Invulnerability.\n");
  say(TPN+" mumbles something in an arcane language.\n");
  }

  ob = clone_object(M_OBJ(minorglobe_ob));
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    return 0;
  }

  ob->move(TP);
  ob->begin_spell(TP);
  return 1;
}
string spellcraft() {
    return (@EndSpell
Minor Globe of Invulnerability (Level IV Wizard Spell - Abjuration)

Cost: 30 Spell Points

The caster is rendered immune to the effects of all spells
of 3rd level and less for a short time.
EndSpell
    );
}
