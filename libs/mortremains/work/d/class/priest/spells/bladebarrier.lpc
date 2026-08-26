//God thank YOU CYANIDE and ILZARION
//for your code
#include <magic.h>
#include <mudlib.h>
#include <m_spells.h>

#define COST 80

int invoke_bladebarrier() {
object blade;

 seteuid(getuid());
 if (present("#BLADEBARRIER#", environment(TP))) {
    write("There is already a Blade Barrier here.\n") ;
return 0;
}

 if (!TP->invoke_spell(COST)) {
  write(NOT_ENOUGH_SP);
 return 0;
}
write ("You begin invoking Blade barrier.\n");

blade = clone_object("/d/class/priest/obj/bladebarrier_ob");
if (!blade) {
  write("Your prayer fizzles.  Contact Darkangel.\n");
   say(TPN+"'s prayer fizzles...\n");
return 0;
}

blade->move(environment(TP));
 blade->start_spell(TP);
return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Blade Barrier (Priest - Level VI - Guardian, Creation)

Duration: 3 rounds			Area of Effect: 1 Room
Cost: 80 TP

	This spell fills a room with swirling blades for 
a few rounds. The blades are harmful to all except the
priest who cast it.
EndSpellcraft
    );
}