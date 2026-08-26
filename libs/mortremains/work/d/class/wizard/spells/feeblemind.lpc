/*
** FILE:        feeblemind.c  (Feeblemind)
** PURPOSE:     5th level enchantment spell.
** COST:        44 SP
** EFFECTS:     Causes target's intellect to degenerate to that of a 
**              moronic child. The subject remains in this state until
**              a heal is used to remove its affects.
** DURATION:    Permanant.
** CREDITS:
**    13 Aug 97  Cyanide wrote the spell.
*/

#include <daemons.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 44

inherit SPELL;

int cast_feeblemind (string str, int obj) {
  object targ, ob;
  int save, level, flag=0;

  seteuid(getuid());

  if (!str) str = ("NONE");
  if (str=="NONE") targ = TP->query_current_attacker();
    else targ = present(str, environment(TP));

  if (!check_valid_targ(TP, targ)) return 0;
  
  if ((environment(TP)->local_spell_effects(({"enchantment"})))==-1)
    return 1;

  if (present("#FEEBLEMIND#", targ)) {
    write("That target has already been feebleminded.\n");
    return 0;
  }

  if (!obj) { 
    if (!TP->cast_spell(COST)) {
      write(NOT_ENOUGH_SP);
      return 0;
    }
    write("You cast feeblemind at ");
    say (TPN+" casts feeblemind at ");
targ->kill_ob(TP);
    if (targ == TP) {
      write("yourself.\n");
      say(objective(TP->query("gender"))+"self.\n");
    } else {
      write(targ->query("cap_name")+".\n");
      say(targ->query("cap_name")+".\n", targ);
      tell_object(targ, "you.\n");
    }
  } 

level = query_caster_level(TP, "wizard");
  if (level < 9) level = 9;

if (!check_magic_resist(level, targ, COST, 0)) return 0;
//save = query_save_mod(caster, targ, ({ "enchantment" }) );
  if (save==-100) return 0;

  PROPERTY_D->query_wis_save_bonus(targ);

  if (targ->query_level("priest")) flag = 1;
  if (targ->query_level("wizard")) flag++;
  if (targ->query("race") != "human") flag = 3;
  switch (flag) {
    case 1 : save+=1; break;     // A priest
    case 2 : save-=4; break;     // A wizard
    case 3 : save-=2; break;     // Combination or nonhuman
  }

  if (targ->save_throw(save)) {
    write(wrap(targ->query("cap_name")+" shakes "+ 
      possessive(targ->query("gender"))+" head to clear it, and continues."));
    tell_object(targ, "Your brain buzzes slightly for a moment.\n");
    return 0;
  }

  ob = clone_object(M_OBJ(feeblemind_ob));
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    return 0;
  }

  ob->move(targ);
  ob->begin_spell(targ);
  return 1;
}
string spellcraft() {
    return (@EndSpell
Feeblemind (Level V Wizard Spell - Enchantment)

Cost: 44 Spell Points

The feeblemind causes the subject's intellect 
to degenerate to that of a moronic child.
EndSpell
    );
}
/* EOF */                 
