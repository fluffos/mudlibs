/*
**  File: bolt.c (Lightning Bolt)
**  Purpose: Single target damage spell.
**  Cost: 7 SP (3rd lvl evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Sep 97  Cyanide edited to be just "bolt"
*/

#define ROLL random(6)+1
#define COST 3
#define SYNTAX "Syntax: cast sunscorch at target\n"  

#include <m_spells.h>
#include <mudlib.h>

 // Prototypes:
void do_lightning (object);

int lvl;
object room, caster, last_hit, *targs;

inherit SPELL;

varargs int invoke_sunscorch (string str, int obj) {   
   object target;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }     
   
   if (!check_valid_targ(TP, target)) return 0;
   if (!obj) {
  if (!TP->invoke_spell(COST)) {
    write("You cannot muster the energies to cast that spell.\n");
    return 1;
  }


      lvl = TP->query_level("priest");
      write("You begin casting Sunscorch...\n"+
         "A brilliant ray of light streams down upon your target.\n");
      tell_room(environment(TP), TPN+" calls down a brilliant ray of light upon "+
         target->query("cap_name")+"!\n", ({ caster, target }) );
       tell_object(target, TPN+" calls a searing ray of light upon you!\n");
   }

   
   room = environment(target);
 //  targs = filter_array(all_inventory(room), "filter_targs", this_object());
   caster = TP;
   
   do_lightning(target);
  // targs-=({ target });
   return 1;
}

void do_lightning (object victim) {
   int dam=0, x;
   string name;

  dam = (random(6)+this_player()->query_level()+1);
  if (victim->query("undead")) dam *= 2;

   if (!victim) return;
   if (living(victim)) {
      name = victim->query("cap_name");
      if (!check_magic_resist((this_player()->query_level("priest")),victim,COST,dam)) return;
//    x = query_save_mod(caster,victim, ({"evocation"}) );
x = 0;
      x = victim->save_throw(x);

      if (x) {
            tell_room(environment(victim), victim->query("cap_name")+
            " dodges the ray!\n", ({ caster, victim }) );
          tell_object(victim, "You manage to dodge the ray!\n");
          write(victim->query("cap_name")+" nimbly dodges your ray!\n");
          return;
        }
      

      dam = victim->receive_damage(dam, "fire", caster);
      victim->kill_ob(caster);

      switch(dam) {
        case -1000..-1 :
           tell_room(room, "The searing ray actually heals "+name+"!\n",
              victim);
           tell_object(victim, "The searing ray actually heals you!\n");
           break;
        case 0 : 
           tell_room(room, name+" just laughs at the spell's puny energies.\n",
              victim);
           tell_object(victim, "The spell leaves you unscathed.\n"+
              "You just laugh.\n");
           break;
        case 1..10 :
           tell_room(room, name+" gets seared slightly.\n", victim);
           tell_object(victim, "You get a small but painful burn.\n");
           break;
        case 11..21 :
           tell_room(room, name+" shrieks as the ray burns "+
              possessive(victim->query("gender"))+" body.\n", victim);
           tell_object(victim, "You shriek as the ray burns you.\n");
           break;
        case 22..31 :
           tell_room(room, name+" grits "+possessive(victim->query("gender"))+
              " teeth against the pain of the burning ray.\n", victim);
           tell_object(victim, "You grit your teeth against the excruciating"+
              " pain!\n");
           break;
        case 32..41 :
           tell_room(room, "The stench of "+name+"'s burnt hair and charred"+
              " flesh fills the room!\n", victim);
           tell_object(victim, "The stench of your burnt hair and charred"+
              " flesh fills the room!\n");
           break;
        default :
           tell_room(room, wrap(name+" screams in mortal pain and outrage"+
              " as "+possessive(victim->query("gender"))+" flesh practically"+
              " melts from "+possessive(victim->query("gender"))+" bones!"));
           tell_object(victim, wrap("You scream in mortal pain and outrage"+
              " as your flesh practically melts from your bones!"));
           break;
      }
   } else {
      name = victim->query("short");
      tell_room(room, "The lightning hits "+name+" and arcs again!\n");
   }
   victim->set("last_attacker", TP);
   return;
}

int filter_targs (object ob) {
   if (wizardp(ob) && ob->query("invisible")) return 0;
   if (!living(ob) && ((int)ob->query("size")<3)) return 0;
   if (ob->query("no_attack")) return 0;
   if (ob==last_hit) return 0;

   return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Sunscorch (Priest - Level I - Sun)

Duration: instant 		Area of Effect: 1 Target
Cost: 3 TP

	This spell damages the target with a beam of
light.
EndSpellcraft
    );
}
