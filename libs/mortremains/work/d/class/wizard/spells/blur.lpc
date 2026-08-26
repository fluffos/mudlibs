/*
** FILE:        blur.c
** PURPOSE:     2nd level illusion spell.
** COST:        12 SP
** EFFECTS:     -2 to caster's AC
** DURATION:    1 min / level.
** CREDITS: 
**    20 Jan 98  Cyanide created the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 12

inherit SPELL;

int cast_blur(string str, int obj) {
  object ob;

  seteuid(getuid());

  if ((environment(TP)->local_spell_effects(({"illusion"})))==-1)
    return 1;

  if (present("#BLUR_OBJECT#", TP)) {
    write("You are already blurred!\n");
    return 0;
  }

  if (!obj) {
    if (!cast_spell(TP, COST)) return 0;

    write("You attempt to cast Blur.\n");
    say(TPN+" mumbles something in an arcane language.\n");
    obj = query_caster_level(TP, "wizard");
  }

  ob = clone_object(M_OBJ(blur_ob));
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    return 0;
  }
  
  write("Your form begins to shift and blur.\n");
  say(capitalize(possessive(TP->query("gender"))) +
    " form begins to shift and blur.\n");

  ob->move(TP);
  ob->begin_spell(TP, obj);
  return 1;
}

string spellcraft() {
	return (@EndSC
Blur (Illusion, 2nd Level Mage Spell)

Duration: 1 minute/level	Area of Effect: The caster

	When a blur spell is cast, the wizard causes the outline of his
form to become blurred, shifting and wavering. This distortion causes 
all combat attacks against the caster to be much more difficult.
EndSC
	);
}

/* EOF */
