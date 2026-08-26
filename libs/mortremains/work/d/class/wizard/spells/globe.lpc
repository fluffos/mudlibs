/*
** FILE:        globe.c
** PURPOSE:     6st level abjuration spell.
** COST:        60 SP
** EFFECTS:     Blocks all spells of about 4th level and below.
** DURATION:    30 seconds/level.
** CREDITS: 
**    21 Jul 97  Cyanide wrote the spell (minorglobe).
**    10 Oct 97  Cyanide changed a little to make it into "globe."
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 60

int cast_globe(string str, int obj) {
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

  write("You attempt to cast Globe of Invulnerability.\n");
  say(TPN+" mumbles something in an arcane language.\n");
  }

  ob = clone_object(M_OBJ(globe_ob));
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
Globe of Invulnerability (Level VI Wizard Spell - Abjuration)

Cost: 60 Spell Points

The caster is rendered immune to the effects of all spells
of 4th level and less for a short time.
EndSpell
    );
}
