//ilz

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 20

string help();

int invoke_venomprot () {
  object shield;

  seteuid(getuid());

  if (present("#PROT_VENOM#", TP)) {
    write("You already have a protection from venom active!\n");
    return 0;
  }

  if (!TP->invoke_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting protection from venom.\n");



  shield = clone_object("/d/class/priest/obj/venomprotection_ob");
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
Protection from Venom (Priest - Level III - Protection)

Duration: 30 sec/lvl 		Area of Effect: Caster
Cost: 20 TP

	This spell protects the caster from poison attacks.
	(1/2 damage).
EndSpellcraft
    );
}