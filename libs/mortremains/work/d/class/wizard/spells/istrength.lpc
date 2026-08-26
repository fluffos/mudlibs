/*
** FILE:        Istrength.c
** PURPOSE:     4th level alteration spell.
** COST:        30 SP
** EFFECTS:     Increases subject's strength by some neat
**                        number depending on class
** DURATION:    40 seconds/level.
** CREDITS: 
**    21 Jul 97  Cyanide wrote the spell. (enlarge which
**                       Aided in the cast at part.)
**    17 Dec 98  Nightmask Used strength.c and enlarge.c
**                         and fucked with it till Istrength was made.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 30

inherit SPELL;

int cast_istrength (string str) {
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

  if ((environment(TP)->local_spell_effects(({"abjuration"})))==-1)
    return 1;

  if (present("#ISTR_OB#", targ)) {
    write("That target has already been magically enhanced.\n");
    return 0;
  }

  if (!TP->cast_spell(COST)) { 
    write("You cannot muster the energies to cast that spell.\n");
    return 0;
  }

  write("You cast improved strength at ");
  say (TPN+" casts improved strength at ");
  if (targ == TP) {
    write("yourself.\n");
    say(objective(TP->query("gender"))+"self.\n");
  } else {
    write(targ->query("cap_name")+".\n");
    say(targ->query("cap_name")+".\n", targ);
    tell_object(targ, "you.\n");
  }

   ob = clone_object(M_OBJ(str_ob.c));
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    return 0;
  }

  ob->move(targ);
  ob->begin_spell(query_caster_level(TP, "wizard"));
  return 1;
}
string spellcraft() {
    return (@EndSpell
Improved Strength (Level IV Wizard Spell - Alteration)

Cost: 30 Spell Points

This spell enhances the targets strength depending on
the class of the recpient. Strength bonuses will vary. 
EndSpell
    );
}
