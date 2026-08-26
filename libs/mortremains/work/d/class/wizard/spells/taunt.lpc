/*
**  File: taunt.c (Taunt)
**  Effects: Causes target to attack TP if he/she/it fails a save.
**  Cost: 7 SP (3rd lvl evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Sep 97  Cyanide edited to be just "bolt"
**    19 Jan 98  Cyanide converted to the "taunt" spell.
**    23 Mar 98  Ilzarion added stuff.
*/

#define ROLL random(6)+1
#define COST 8
#define SYNTAX "Syntax: cast taunt at target\n"  

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

varargs int cast_taunt (string str, int obj) {   
   string name;
   object target;
   int x;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }     
   
   if (!check_valid_targ(TP, target)) return 0;
   if (!obj) {
      obj = query_caster_level(TP, "wizard");
      if (!cast_spell(TP, COST)) return 0;

      write("You begin casting Taunt...\n");
      say(TPN+" begins uttering arcane words...\n");

      tell_room(environment(TP), TPN+" shouts a challenge at "+
         target->query("cap_name")+"!\n", ({ TP, target }) );
      write("You shout a challenge at "+target->query("cap_name")+".\n");
      tell_object(target, TPN+" shouts a challenge at you!\n");
   }

   if (!target) return;
   name = target->query("cap_name");
   if (!check_magic_resist(obj,target,COST,0)) return; 
   x = 0;
// x = query_save_mod(TP,tagret, ({"enchantment"}) );
   x = target->save_throw(x);

   if (x) {
      tell_room(environment(TP), name + " ignores the challenge.\n",
         ({ TP, target }) );
      write(name + " ignores your challenge.\n");
      tell_object(target, "You ignore the challenge.\n");
   } else {
      tell_room(environment(TP), name + " turns to attack " +
         TPN+ "!\n", ({ TP, target }) );
      write(name+" turns to attack you!\n");
      tell_object(target, "You are compelled to attack "+TPN+"!\n");
   }
   
   if (!interactive(target)) target->set("aggressive", 9);

   target->stop_all_attacks();
   target->kill_ob(TP);
}

string spellcraft() {
   return (@EndHelp
Taunt  (Level III Wizard Spell - Evocation)

Cost: 8 Spell Points

A taunt spell enables the caster to challenge a single creature with an
Intelligence of 2 or greater. The caster need not speak the language of 
the creatures. His words and sounds have real meaning for the subject 
creature or creatures, challenging, insulting, and generally irritating 
and angering the listeners. Those succumbing to the spell rush forth in
fury to do battle with the spellcaster.
This spell also causes a monster to react with the same fury to all who
cross it's path thereafter.
EndHelp
   );
}

/* EOF */
