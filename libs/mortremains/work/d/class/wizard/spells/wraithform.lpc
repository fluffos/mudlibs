/*
** FILE:        wraithform.c
** PURPOSE:     3rd level alteration/illusion spell.
** COST:        20 SP
** EFFECTS:     1 - Makes you immune to weapons of less than +1 enchantment
**              2 - You cannot cast or attack!
** DURATION:    30 seconds/level.
** CREDITS: 
**    21 Jul 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 20

inherit SPELL;

int cast_wraithform(string str, int obj) {
  object ob;

  seteuid(getuid());

  if ((environment(TP)->local_spell_effects(({"alteration", "illusion"})))==-1)
    return 1;

  if (present("#WRAITHFORM#", TP)) {
    write("You already have wraithform cast upon you!\n");
    return 0;
  }

  if (!obj) {
    if (!cast_spell(TP, COST)) return 0;

    write("You attempt to cast Wraithform.\n");
    say(TPN+" mumbles something in an arcane language.\n");
    obj = query_caster_level(TP, "wizard");
  }

  ob = clone_object(M_OBJ(wraithform_ob));
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    return 0;
  }

  ob->move(TP);
  ob->begin_spell(TP, obj);
  return 1;
}
string spellcraft() {
    return (@EndSpell
Wraithform (Level III Wizard Spell - Alteration / Illusion)

Cost: 20 Spell Points

This spell gives the caster immunity to nonmagical
weapons. However, the caster may not attack or cast
spells without halting the spell.
EndSpell
    );
}