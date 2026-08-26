/*
**ILZ
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

#define COST 120

string help();

int cast_prismsphere () {
  object shield;

  seteuid(getuid());

  if (present("#PRISMATIC_SPHERE#", TP)) {
    write("You already have a prismatic sphere active!\n");
    return 0;
  }

   if (!cast_spell(TP, COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting prismatic sphere.\n");

  say ("Begins muttering arcane verses...\n");

  shield = clone_object(M_OBJ(prismsphere_ob.c));
  if (!shield) {
    write("Your spell fizzles.  Contact Cyanide.\n");
    say(TPN+"'s spell fizzles...\n");
    return 0;
  }

  shield->move(TP);
  shield->start_spell(TP);
  return 1;
}

string spellcraft() {
	return (@EndSC
Prismsphere (Abjuration, 9th Level Mage Spell)
Duration: until broken through or caster moves.	Area of Effect: The caster
	This spell enables the wizard to conjure up an immobile, opaque globe
of shimmering, multicolored light to surround him, giving protection from all 
forms of attack. The sphere can be destroyed, color by color, in consecutive
order by attacking the caster; however, the first must be brought down before 
the second can be affected, and so on. Any creature passing through the barrier
receives the effect of every color still remaining.
The following table shows the colors and effects of the prismatic sphere:
Red    1st -inflicts 60 points of damage, save for half
Orange 2nd -inflicts 120 points of damage, save for half	
Yellow 3rd -inflicts 240 points of damage, save for half
Green  4th -save or suffer 120 points of poision; save for half 	
Blue   5th -save or turn to stone
Indigo 6th -save or be feebleminded
Violet 7th -save or be sent to another plane
EndSC
	);
}
