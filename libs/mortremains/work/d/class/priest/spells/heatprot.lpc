//ilz

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 12

string help();

int invoke_heatprot () {
  object shield;

  seteuid(getuid());

  if (present("#PROT_HEAT#", TP)) {
    write("You already have a protection from heat active!\n");
    return 0;
  }

  if (!TP->invoke_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting protection from heat.\n");



  shield = clone_object("/d/class/priest/obj/heatprotection_ob");
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
Protection from Heat (Priest - Level II - Protection)

Duration: 30 sec/lvl 		Area of Effect: Caster
Cost: 12 TP

	This spell helps protect the caster from fire 
attacks. It is cumulative with the higher level version
fireprot.
EndSpellcraft
    );
}
