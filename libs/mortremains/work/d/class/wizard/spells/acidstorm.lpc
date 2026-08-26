/* The Acid Storm Spell.
  11-01-96 Chronos.
  04-28-98 Cyanide moved and converted to the new lib.

  Cost: 100 sp.
  Duration: 1 min per level.
*/

#include <m_spells.h>

#define COST 80

inherit SPELL;

int cast_acidstorm() {
    object storm;
    int power;

    seteuid(getuid());
    if (present("#ACIDSTORM#", environment(TP))) {
	write("There is already acid rain here.\n") ;
	return 1;
    }

    storm = clone_object(M_OBJ(acidstorm_ob));
    if (!storm) {
	write("You can't cast that spell right now, notify"+
	  " Cyanide.\n");
	return 1;
    }

    if (!cast_spell(TP, COST)) return 1;

    write("You cast an intricate spell..\n") ;
    say(TPN+"'s voice booms out a mystical incantation.\n");
    tell_object(environment(TP), 
      "Acid begins raining down from above!\n") ;

    storm->move(environment(TP));
    power = TP->query_level("wizard");
    storm->start_spell(power,TP);
    return 1;
}


string spellcraft() {
    return (@EndSpell
Acid Storm (Level VII Wizard Spell - Evocation)

Cost: 80 Spell Points

This deadly spell unleashes a downpour of magical, gelatinous
acid droplets. All creatures within the area of effect are 
coated by globs of gooey acid
EndSpell
    );
}

/* EOF */
