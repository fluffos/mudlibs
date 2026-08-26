/*
** FILE:        infravision.c
** PURPOSE:     3rd level alteration spell.
** COST:        20 SP
** EFFECTS:     Gives caster the benefits of infravision.
** DURATION:    90 seconds/level.
** CREDITS: 
**    09 Nov 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 20
#define SYNTAX "Syntax: cast infravision at (recipient)\n"

inherit SPELL;

int cast_infravision(string str, int obj) {
  object ob, targ;

  seteuid(getuid());

  if ((environment(TP)->local_spell_effects(({"alteration"})))==-1)
    return 1;

  if (present("#INFRAVISION#", TP)) {
    write("You already are benefitting from infravision.\n");
    return 0;
  }

  if (!obj) {
    if (!cast_spell(TP, COST)) return 0; 

    write("You attempt to cast Infravision.\n");
    say(TPN+" mumbles something in an arcane language.\n");
    obj = query_caster_level(TP, "wizard");
  }

  ob = clone_object(M_OBJ(infravision_ob));
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    return 0;
  }

  ob->move(TP);
  ob->begin_spell(TP, obj);
  return 1;
}
string spellcraft() {
   return (@EndCraft
Mirror Image (Wizard  Level III  Alteration)

Area of Effect: Caster		Saving Throw: None
Cost: 20 SP
Duration: 1.5 minute per level

   This spell gives the caster the benefits of
infravision ability.
EndCraft
   );
}
/* EOF */
