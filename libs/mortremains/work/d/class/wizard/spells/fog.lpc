// The fog spell.
// Written by Chronos.  From Scratch!  Tomorrow is my birthday.
// Cost = 45 sp.
// 12 Dec 98  Cyanide updated to the NK conventions, but left it
//      otherwise intact. :) 

#include <m_spells.h>
#include <mudlib.h>

#define COST 12

inherit SPELL;

int cast_fog() {
  object fog;

  seteuid(getuid());

  if (present("#FOG_OBJECT#", environment(TP))) {
    write("It already quite foggy in here.\n");
    return 0;
  }

  if ((environment(TP)->local_spell_effects(({"invocation"})))==-1)
    return 1;

  if (!cast_spell(TP, COST)) {
    write("You don't have the power to cast that spell.\n");
    return 1;
  }

  fog=clone_object(M_OBJ(fog_object));
  if (!fog) {
    write("Your spell fails.  Notify Cyanide.\n");
    return 0;
  }
  fog->move(environment(TP));
  fog->set("enchantment", 1);
  fog->set("level", query_caster_level(TP, "wizard"));
  fog->set("caster", TP);
  fog->set("schools", ({ "evocation" }) );

  write("You cast fog.\n");
  say(TPN + " casts a spell.\n");
  tell_object(environment(TP), 
  "A dense fog suddenly rises from the ground, making it impossible to see.\n");
  fog->start_spell(30 * query_caster_level(TP, "wizard")) ;
  return 1;
 }

string spellcraft() {
	return (@EndSC
Fog (Evocation, 2nd Level Mage Spell)

Duration: 30 seconds/level	 Area of Effect: 1 Room

	When a this spell is cast, it fills the room with thick fog, 
making it impossible to see.
EndSC
	);
}
