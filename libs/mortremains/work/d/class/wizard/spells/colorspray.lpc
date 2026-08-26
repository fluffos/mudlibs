/*
**  File: colorspray.c (Color Spray)
**  Purpose: Combat spell
**  Effects: Possibly blinds, stuns, or knocks unconscious the target.
**  Cost: 8 SP (1st level alteration)
**  Credits:
**    14 Nov 97  Cyanide created the file.
*/

#define COST 8
#define SYNTAX "Syntax: cast colorspray at target\n"

#include <m_spells.h>
#include <mudlib.h>
#include <magic.h>

inherit SPELL;

varargs int cast_colorspray (string str, int obj) {
   string name, they_see;
   object target = 0;
   int x;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return NO_TARGET;
   }     

   if (!check_valid_targ(TP, target)) return INVALID_TARGET;
   if (!obj) {
      if (!cast_spell(TP, COST)) return NO_STRENGTH;

      write("You begin casting Color Spray...\n");
      say(TPN+" begins uttering arcane words...\n");

      tell_room(environment(TP), wrap("A vivid spray of clashing colors"+
         " springs forth from "+TPN+"'s hand toward "+
         target->query("cap_name")+"!"), ({ TP, target }) );
      write("You shoot a vivid spray of clashing colors at "+
         target->query("cap_name")+".\n");
      tell_object(target, "A vivid spray of clashing colors springs "+
         "forth from "+TPN+"'s hand toward you!\n");
      obj = query_caster_level(TP, "wizard");
   }
   
   name = target->query("cap_name");
   if (!visible(TP, target)) name = "Somebody";
   if (!check_magic_resist(obj,target,COST,0)) return MAGIC_RESISTANCE;

   x=0;
// x = query_save_mod(TP,target, ({"evocation"}) );
   x = target->save_throw(x);               // Roll a saving throw
   if (target->query_level() < 6) x = 0;    // No save if <6 HD/lvls.
   if (target->query("blind")) x = 1;       // Blind are immune.

   if (x) {
     if (target->query_skill("Evasion")) {
       tell_room(environment(target), target->query("cap_name")+
         " nimbly dodges the color spray!\n", ({ TP, target }) );
       tell_object(target, "You manage to dodge the color spray!!\n");
       write(target->query("cap_name")+" nimbly dodges the color spray!\n");
       return SAVED;
     }

     tell_room(environment(target), target->query("cap_name")+" averts "+
       possessive(target->query("gender"))+" eyes.\n", ({ target }) );
     tell_object(target, "You manage to avert your eyes!\n");
     return SAVED;
   } else {

     target->set("last_attacker", TP);
     target->kill_ob(TP);
     they_see = name+" is struck in the eyes by the color spray ";
     name = "You are struck in the eyes by the color spray ";

     obj = obj - target->query_level();

     switch(obj) {
       case -200..-3 :
         they_see += "and is stunned!";
         name += "and are stunned!";
         target->set("stunned", 2);
         break;
       case -2..-1 :
         they_see += "and is blinded!";
         name += "and are blinded!";
target->set("blind", random(4)+1);
         break;
       default :
         they_see += "and is struck unconscious!";
         name += "and are struck unconscious!" ;
         target->set("rest", 2);
         break;
     }

     tell_room(environment(target), wrap(they_see), ({ target }) );
     tell_object(target, wrap(name));
     target->kill_ob(TP);
   }
   return SPELL_CAST;
}
string spellcraft() {
    return (@EndSpell
Color Spray (Level I Wizard Spell - Alteration)

Cost: 8 Spell Points

This useful spell possibly blinds, stuns, or 
knocks unconscious the target.
EndSpell
    );
}
