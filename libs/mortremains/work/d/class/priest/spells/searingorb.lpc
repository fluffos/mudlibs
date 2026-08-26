

#define ROLL random(6)+1
#define COST 60
#define SYNTAX "Syntax: invoke searingorb at target\n"  

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

 // Prototypes:



varargs int invoke_searingorb (string str, int obj) {   
   object target, room;
   int x, y, lvl, dam;
	string name;


   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }     
   
   if (!check_valid_targ(TP, target)) return 0;
   if (!obj) {
      if (!TP->invoke_spell(COST)) return 0;
      
      write("You enchant a topaz with the light of the sun...\n");
      say(TPN+" prays over a brilliant topaz...\n");

      tell_room(environment(TP), TPN+" hurls a glowing gem at "+
         target->query("cap_name")+"!\n", ({ TP, target }) );
write("You hurl the gem at "+target->query("cap_name")+".\n");
      tell_object(target, TPN+" hurls a glowing gem at you!\n");
   } else {
     lvl = obj;
   }

   room = environment(target);

     for (x=0; x<6; x++)  dam+=ROLL;

   
   
   if (!target) return;
   name = target->query("cap_name");
   if (!check_magic_resist(lvl,target,COST,dam)) return;

   x=0;
// x = query_save_mod(TP,target, ({"evocation"}) );
   x = target->save_throw(x);
if (target->query("undead")) dam *=2;
   if (x) {
     dam/=2;
     if (target->query_skill("Evasion")) {
       tell_room(environment(target), target->query("cap_name")+
         " manages to find cover!\n", ({ TP, target }) );
       tell_object(target, "You manage to find cover!\n");
       write(target->query("cap_name")+" jumps aside and finds cover!\n");
       return;
     }
   }

   y = TP->query_hit(target, 4);
if (y){
  tell_object(target, "You are hit with the gem!\n");
       write(target->query("cap_name")+" is hit with the gem!\n");
       if(!x){
		tell_object(target, "You are stricken blind!\n");
       write(target->query("cap_name")+" is stricken blind!\n");
       target->add("blind", (random(6)+1));
       }
}

	if (!y) dam/=2;

   dam = target->receive_damage(dam, "fire", TP);
   target->kill_ob(TP);

   switch(dam) {
     case -10000..-1 :
        tell_room(room, "The naked flame actually heals "+name+"!\n",
          target);
        tell_object(target, "The naked flame actually heals you!\n");
        break;
     case 0 : 
        tell_room(room, name+" stands unaffected by the inferno.\n",
           target);
        tell_object(target, "You stand unaffected by the inferno.\n"+
           "You just laugh.\n");
        break;
     case 1..12 :
        tell_room(room, name+"'s hair gets singed a bit.\n", target);
        tell_object(target, "Your hair gets singed a bit.\n");
        break;
     case 13..26 :
        tell_room(room, name+"'s body gets blistered.\n", target);
        tell_object(target, "Your body gets blistered.\n");
        break;
     case 27..42 :
        tell_room(room, wrap("Painfuls burns cover "+name+
          "'s chest and arms."), target);
        tell_object(target, "Painful burns cover your chect and arms.\n");
        break;
     default :
        tell_room(room, wrap(name+"'s skin peels away and "+
          possessive(target->query("gender"))+" hair burns in the "+
          "flames!"), target);
        tell_object(target, "Your skin peels away and your hair burns "+
          "in the flames!\n");
        break;
   }
   target->set("last_attacker", TP);
   return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Sol's Searing Orb (Priest - Level VI - Sun)

Duration: instant 		Area of Effect: 1 Target
Cost: 60 TP

	The priest hurls a fiery gem at the target,
burning thier flesh. It is especially effective
against undead.
EndSpellcraft
    );
}
