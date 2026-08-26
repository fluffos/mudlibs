/*
**  File: disintegrate.c (Disintegrate)
**  Purpose: Combat spell
**  Effects: Utter annhilates the target.
**  Cost: 60 SP (6th level evocation)
**  Credits:
**    9 Nov 97  Cyanide created the file.
*/

#define COST 60
#define SYNTAX "Syntax: cast disintegrate at target\n"

#include <m_spells.h>
#include <mudlib.h>
#include <config.h>

 // Prototypes:
void do_swarm (object);
void begin_hell (object);

inherit SPELL;

varargs int cast_disintegrate (string str, int obj) {
   string name;
   object target = 0, caster;
   int x;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }     
   caster=TP;
   if (!check_valid_targ(TP, target)) return 0;
   if (!obj) {
      if (!cast_spell(TP, COST)) return 0; 

      write("You grin evilly and begin casting Disintegrate...\n");
      say(TPN+" grins evilly and begins uttering arcane words...\n");

      tell_room(environment(TP), wrap("A thin green ray shoots from "+TPN+
         "'s hand toward "+target->query("cap_name")+"!"), ({ caster, target }) );
      write("You shoot a green ray at "+target->query("cap_name")+".\n");
      tell_object(target, TPN+" shoots a thin green ray at you!\n");
      obj = query_caster_level(TP, "wizard");
   }
   
   name = target->query("cap_name");
   if (!visible(caster, target)) name = "Somebody";
   if (!check_magic_resist(obj,target,COST,1000)) return;

   x=0;
// x = query_save_mod(caster,target, ({"evocation"}) );
   x = target->save_throw(x);
   if (target->query_level() > obj) x = 1;

   if (x) {
     if (target->query_skill("Evasion")) {
       tell_room(environment(target), target->query("cap_name")+
         " nimbly dodges the ray!\n", ({ caster, target }) );
       tell_object(target, "You manage to dodge the ray!!\n");
       write(target->query("cap_name")+" nimbly dodges the ray!\n");
       return;
     }

     tell_room(environment(target), TPN+"'s ray misses "+
       target->query("cap_name")+" by an inch.\n", ({ caster, target }) );
     tell_object(target, "You barely manage to dodge the ray!\n");
     write("Your ray misses "+target->query("cap_name")+
       " by an inch!\n");
     return 1;     
   }

   target->kill_ob(caster);
   x = target->receive_damage(1000, "wizard", caster);
   target->set("last_attacker", caster);

   if (!x) {
     tell_room(environment(target), target->query("cap_name")+
       " ignores the ray!\n", ({ caster, target }) );
     tell_object(target, "You simply ignore the ray!\n");
     write(capitalize(target->query("cap_name"))+" simply ignores "+
       "the ray!\n");
     return 1;
   } else {
     tell_room(environment(target), wrap(target->query("cap_name")+
       " screams as "+subjective(target->query("gender"))+" slowly "+
       " disintegrates into nothingness.\n"), ({ caster, target }) );
     tell_object(target, "You look on in horror as you watch yourself slowly dissolving!");
     write(target->query("cap_name")+" watches in horror as "
       +subjective(target->query("gender"))+" slowly disintegrates!\n");
     target->set("last_attacker", TP);
     if (target->query("hit_points") < 0) target->move(VOID);
   }
   return 1;
}
string spellcraft() {
    return (@EndSpell
Acid Storm (Level VI Wizard Spell - Alteration)

Cost: 60 Spell Points

This deadly spell disintegrates the target and all
items carried. Nothing remains. Powerful creatures
are know to resist this effect easily, while lesser
creatures succumb more readily.
EndSpell
    );
}
