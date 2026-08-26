

#define ROLL random(8)+random(8)+random(8)+random(8)+random(8)+random(8)+6
#define COST 15 
#define SYNTAX "Syntax: cast flamestrike at target\n"  

#include <m_spells.h>
#include <mudlib.h>

 // Prototypes:
void do_lightning (object);

int lvl;
object room, caster, last_hit, *targs;

inherit SPELL;

varargs int invoke_flamestrike (string str, int obj) {   
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
      write("You begin casting Flamestrike...\n");
      say(TPN+" begins summoning the power of fire...\n");

      tell_room(environment(TP), TPN+" calls a pillar of fire upon "+
      target->query("cap_name")+"!\n", ({ caster, target }) );
      write("You call a pillar of fire upon "+target->query("cap_name")+".\n");
      tell_object(target, TPN+" calls a pillar of fire upon you!\n");
   }
target->kill_ob(this_object());
   room = environment(target);
   targs = filter_array(all_inventory(room), "filter_targs", this_object());
   caster = TP;
   do_lightning(target);
   targs-=({ target });
   return 1;
}

void do_lightning (object victim) {
   int dam=0, x, lvl;
   string name;

   caster = TP;
   lvl = caster->query_level("priest");

  dam = (ROLL);

   if (!victim) return;
 
      name = victim->query("cap_name");
      if (!check_magic_resist(lvl,victim,COST,dam)) return;
//    x = query_save_mod(caster,victim, ({"evocation"}) );
      x = victim->save_throw(x);
if (x){
 if (victim->query_skill("Evasion")){
         tell_room(room, name+" Dodges the pillar of flame!\n",
              victim);
           tell_object(victim, "You dodge the pillar of flame!\n");
 }
 dam = (dam/2);
}

      dam = victim->receive_damage(dam, "fire", caster);
 
      switch(dam) {
        case -1000..-1 :
           tell_room(room, "The flame actually heals "+name+"!\n",
              victim);
           tell_object(victim, "The flame actually heals you!\n");
           break;
        case 0 : 
           tell_room(room, name+" just laughs at the spell's puny energies.\n",
              victim);
           tell_object(victim, "The spell leaves you unscathed.\n"+
              "You just laugh.\n");
           break;
        case 1..10 :
           tell_room(room, name+" escapes most of the flame.\n", victim);
           tell_object(victim, "You escape most of the flame.\n");
           break;
        
        case 11..20 :
           tell_room(room, wrap(name+" is charred by the pillar of flame!\n"));
           tell_object(victim, wrap("You are charred a bit by the flames!\n"));
           break;
      default :
           tell_room(room, wrap(name+" is engulfed by the pillar of flame!\n"));
           tell_object(victim, wrap("You are engulfed by the flames!\n"));
           break;

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
Flame Strike (Priest - Level V - Combat)

Duration: instant 		Area of Effect: 1 Target
Cost: 15 TP

	This spell damages the target with a pillar
of roaring fire.
EndSpellcraft
    );
}
