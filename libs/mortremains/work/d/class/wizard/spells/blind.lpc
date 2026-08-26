/*
**  File: stun.c (Power Word Blind)
**  Purpose: Level 8 mage conjuration spell.
**  Cost: 100 SP (8th lvl Conjuration)
*/

#define COST 100
#define SYNTAX "Syntax: cast blind at target\n"  
#define MAX_HP_AFFECTED 330

#define FIND find_player("cyanide")
#define DEBUG(x) if(FIND) tell_object(FIND, x)

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

varargs int cast_blind (string str, int obj) {   
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
      tell_object(target, "A bright flash fills your sight, and you stand reeling, unable to see.\n");
      tell_room(environment(TP), target->query("cap_name") + " is blinded!\n", ({ target }) );

   switch(target->query("hit_points")){
      case 0..110 : rolled = ( random(4)+random(4)+random(4)+random(4)+4 );break;
      case 111..220 : rolled = ( random(4)+random(4)+2 );break;
      case 221..330 : rolled = ( random(4)+1 );break;
      default : rolled = (0);
   }
     
      target->set("blind", rolled);
   } else {
      tell_object(target, "A flash fills your sight, but you shake it off.\n");
      tell_room(environment(TP), target->query("cap_name") + " clears "+
         possessive(target->query("gender")) + " eyes and continues.\n", ({ target }));
   }

   target->kill_ob(TP);
   return 1;
}
string spellcraft() {
    return (@EndSpell
Power Word Blind (Level VIII Wizard Spell - Conjuration)

Cost: 100 Spell Points

This spell blinds a target. Resistance is determined
by the hit points of the target. Very high hit points
make one immune.
EndSpell
    );
}

/* EOF */
/* EOF */

