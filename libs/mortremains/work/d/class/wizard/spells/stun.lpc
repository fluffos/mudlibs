/*
**  File: stun.c (Power Word Stun)
**  Purpose: Level 7 mage conjuration spell.
**  Cost: 80 SP (7th lvl Conjuration)
**  Credits:
**    24 Sep 97  Cyanide wrote this while not paying any attention in class.
*/

#define COST 80
#define SYNTAX "Syntax: cast stun at target\n"  
#define MAX_HP_AFFECTED 270
//#define ROLL random(4) + 1

#define FIND find_player("cyanide")
#define DEBUG(x) if(FIND) tell_object(FIND, x)

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

varargs int cast_stun (string str, int obj) {   
   object target;
   int rolled;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }   
   if (!check_valid_targ(TP, target)) return 0;
   if (!obj) {
      if (!TP->cast_spell(COST)) {
         write(NOT_ENOUGH_SP);
         return 0;
      }
      write("You invoke ancient magicks to affect "+target->query("cap_name")+".\n");
      say(TPN+" invokes ancient magicks to affect "+target->query("cap_name") + ".\n");
   }
   if ((int)target->query("hit_points") <= MAX_HP_AFFECTED) {
      tell_object(target, "A roar fills your ears and you stand reeling, unable to think.\n");
      tell_room(environment(TP), target->query("cap_name") + " is stunned!\n", ({ target }) );

   switch(target->query("hit_points")){
      case 0..90 : rolled = ( random(4)+random(4)+random(4)+random(4)+4 );break;
      case 91..120 : rolled = ( random(4)+random(4)+2 );break;
      case 121..270 : rolled = ( random(4)+1 );break;
      default : rolled = (0);
   }

      target->block_attack(rolled);
      target->set("stunned", rolled);
   } else {
      tell_object(target, "A roar fills your ears, but you shake it off.\n");
      tell_room(environment(TP), target->query("cap_name") + " clears "+
         possessive(target->query("gender")) + " head and continues.\n", ({ target }));
   }

   target->kill_ob(TP);
   return 1;
}
string spellcraft() {
    return (@EndSpell
Power Word Stun (Level VII Wizard Spell - Conjuration)

Cost: 80 Spell Points

This spell stuns a target. Resistance is determined
by the hit points of the target. Very high hit points
make one immune.
EndSpell
    );
}

/* EOF */
/* EOF */

