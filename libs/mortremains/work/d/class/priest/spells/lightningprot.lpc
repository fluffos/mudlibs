//ilz

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 30

string help();

int invoke_lightningprot () {
  object shield;

  seteuid(getuid());

  if (present("#PROT_LIGHTNING#", TP)) {
    write("You already have a protection from lightning active!\n");
    return 0;
  }

  if (!TP->invoke_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting protection from lightning.\n");



  shield = clone_object("/d/class/priest/obj/lightningprotection_ob");
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
Protection from Lightning (Priest - Level IV - Protection, Weather)

Duration: 30 sec/lvl 		Area of Effect: Caster
Cost: 30 TP

	This spell protects the caster from lightning attacks.
	(1/2 damage).
EndSpellcraft
    );
}
