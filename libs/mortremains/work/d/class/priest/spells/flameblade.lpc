//ilz

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 12

string help();

int invoke_flameblade () {
  object shield;

  seteuid(getuid());

 

  if (!TP->invoke_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting flameblade.\n");



  shield = clone_object("/d/class/priest/obj/flameblade_ob");
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
    return (@EndSpellcraft
Flame Blade (Priest - Level II - Fire)

Duration: 1 min/lvl 		Area of Effect: Caster
Cost: 12 TP

	This spell creates a magical blade of fire
which must be wielded by the caster.
EndSpellcraft
    );
}
