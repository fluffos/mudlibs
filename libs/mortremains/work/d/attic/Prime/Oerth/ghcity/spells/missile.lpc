

#define ROLL random(4)+2
#define COST 3
#define SYNTAX "Syntax: cast missile at target\n"  

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

varargs int cast_missile (string str, int obj) {   
   object target;
   int dam=0, x, lvl;
   string vname, vobj, vposs;
   string victim, attacker;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }     
   
   if (!check_valid_targ(TP, target)) return 0;
   if (!obj) {
      if (!cast_spell(TP, COST)) return 0;

      lvl = query_caster_level(TP, "wizard");
      write("You begin casting Magic Missile...\n");
      say(TPN+" begins uttering arcane words...\n");

      tell_room(environment(TP), TPN+" hurls a magic missile at "+
         target->query("cap_name")+"!\n", ({ TP, target }) );
      write("You hurl a magic missile at "+target->query("cap_name")+".\n");
      tell_object(target, TPN+" hurls a magic missile at you!\n");
   } else {
      lvl = obj;
   }

   // Number of missiles = 1 per 2 levels after 1st (1 at 1, 2 at 3, etc.)
   lvl = 1 + (lvl/2);
   if (lvl>5) lvl=5;
   for (x=0; x<lvl; x++) dam+=ROLL;

if (!check_magic_resist(lvl,target,COST,dam)) return;

   dam = target->receive_damage(dam, "force", TP);
   target->kill_ob(TP);

   vname = target->query("cap_name");
   vobj = objective(target->query("gender"));
   vposs = possessive(target->query("gender"));

/*
**  These are the variables that we have:
**  TPN			Attacker name
**  vname 		Victim name
**  vobj		Objective of victim
**  vposs		Possessive of victim
**  victim      What the victim sees
**  attacker	What the attacker sees
**  str			What the observer sees
*/
   switch(dam) {
      case -1000..-1 :
         victim = "Your wounds close as you absorb the pure force.";
         attacker = vname+"'s wounds close as "+vobj+" absorbs the missiles!";
         str = attacker;
         break;
      case 0 : 
         attacker = "Your missiles pass harmlessly through "+vname+"\n"+
            vobj+" just laughs.";
         str = TPN+"'s missiles pass harmlessly through "+vname+"\n"+
            "He just laughs";
         victim = "The spell leaves you unscathed.\nYou just laugh.\n";
         break;
     case 1..7 :
         attacker = "A single missile strikes "+vname+", doing little damage.";
         str = attacker;
         victim = "A single missile hits home, but does little damage.";
         break;
     case 8..14 :
         victim = "You are slightly hurt as two force missiles strike you.";
         attacker ="Two missiles strike "+vname+", hurting "+vobj+" slightly.";
         str = attacker;
         break;
     case 15..21 :
         attacker = vname+" is struck by multiple missiles, doing considerable damage.";
         str = attacker;
         victim = "Multiple missiles strike you, damaging you considerably.";
         break;
     case 22..28 :
         attacker = vname+" is seriously wounded by your magical assault!";
         str = vname+" is seriously wounded by "+TPN+" magical assault!";
         victim = "You are seriously wounded by "+TPN+"'s magical assault!";
         break;
     case 29..35 :
         victim = "A flurry of glowing missiles slam devastatingly into you!";
         attacker = "A flurry of magical missiles slam in "+vname+
            ", devastating "+vobj+"!";
         str = attacker;
         break;
     default :
         victim = "Your very flesh is blasted from your bones as a "
            +"swarm of missiles annihilate you!";
         attacker = vname+"'s very flesh is blasted from "+vposs+" bones as a "+
            "swarm of missiles annihilate "+vobj+"!";
         str = attacker;
         break;
   }

   tell_room(environment(TP), wrap(str), ({ TP, target }) );
   tell_object(target, wrap(victim));
   tell_object(TP, wrap(attacker));

   target->set("last_attacker", TP);
   return;
}
