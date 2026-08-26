//ilz

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 20

string help();

int invoke_fireprot () {
  object shield;

  seteuid(getuid());

  if (present("#PROT_FIRE#", TP)) {
    write("You already have a protection from fire active!\n");
    return 0;
  }

  if (!TP->invoke_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting protection from fire.\n");



  shield = clone_object("/d/class/priest/obj/fireprotection_ob");
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
Protection from Cold (Priest - Level III - Protection, Fire)

Duration: 30 sec/lvl 		Area of Effect: Caster
Cost: 20 TP

	This spell protects the caster from fire attacks.
	(1/2 damage).
EndSpellcraft
    );
}
