
/*
Converted to base command by
Malik Sept 97
*/
/* many + Taniwha, Manshoon, Baldrick and Wonderflug made this */



inherit "/std/commands/base_command";

#include "new_tweaks.h"


int backstab_damage(object doer,object target, object weapon);
void do_circle(object doer, object target, int dam);
int sense_check(object doer, object target);


void setup(){
   set_command_name("backstab");
   target_type = BACKSTAB_TYPE;
   sec_lockout = BACKSTAB_LOCKOUT;
   sec_lock_prop = BACKSTAB_LOCK_PROP;
   guilds = BACKSTAB_GUILDS;

   set_help_string(
    "Syntax: backstab <person>\n\n"
    "Backstab is based on your level and dexterity. "
    "Your victim has a chance of sensing the backstab and thus avoiding "
    "it based on his level, wisdom and intelligence. "
    "Wether you are successful or not, the victim will attack you.\n\n"
    "You need a piercing weapon to be able to backstab and you must be "
    "hidden.\nThe cost is level dependent.\n\n"
    "You may also backstab during a fight, provided someone "
    "is there to distract your opponent long enough for you "
    "to work your way behind them.  In this case the cost is "
    "4 GP per round of circling that you need to do.\n\n"
    "Example\n> backstab merchant\n");

} /* setup() */


int backstab(string str, object obj){

   return ::exec_command(str,obj);
} /* backstab() */


int do_command(object target, object doer){
   int i, cost, damage;
   object *weap;
   string wname, tname, dname;

   cost = doer->query_level();
   cost = (cost > 24 ? 24 : cost);
   if(doer->query_gp() < cost){
      tell_object(doer, "You're too tired to backstab again.\n");
      return 1;
   }

   if(doer->query_level() < 10){
      tell_object(doer,"You find yourself too unskilled to backstab.\n");
      return 1;
   }
   weap = doer->query_weapons_wielded();
   if(!sizeof(weap)){
      tell_object(doer,"Your fingers aren't really sharp enough to "
       "backstab someone with.\n");
      return 1;
   }

   damage = 0;
   for (i=0;i<sizeof(weap);i++){
      if(weap[i]->query_attack_type() == 3) 
         damage += backstab_damage(doer,target,weap[i]);
      else{
         tell_object(doer,"It would be rather impossible to shove a "+
         weap[i]->query_short()+" in someone's back.\n");
         return 1;
      }
   }

   if (i>=sizeof(weap)) 
      i=0;

   wname = weap[i]->query_short();
   tname = target->query_short();
   dname = doer->query_short();   

   if(already_attacking(doer,target) == 1){
      do_circle(doer, target, damage);
      return 1;
   }
   if(already_attacking(doer,target) == 2){
      tell_object(doer, "Wouldn't be a good idea to neglect your other "
       "attackers and backstab someone else.\n");
      return 1;
   }

   doer->add_timed_property(sec_lock_prop,100,sec_lockout);

   if(sense_check(doer,target)){
      tell_object(doer,"Oh bugger, "+tname+" seems to have sensed your "
       "intentions!\n");
      command_cost(cost/3,doer);
   }
   else {
     // Fake event triggers, for "special" weapons - Radix
      for(i=0; i<sizeof(weap); i++)
         weap[i]->event_backstab(damage,doer,target);
      command_cost(cost,doer);
      command_damage(-damage,doer,target);
      tell_object(target,"You convulse in agony as "+dname+" places a "+
       wname+" in your back!\nThat really did hurt!\n");
      tell_room(environment(doer), tname+" convulses in agony as "+dname+
       " places a"+wname+" in "+target->query_possessive()+" back!\n",
       ({ doer, target }) );
      tell_object(doer,tname+" convulses in agony as you place a "+wname+
       " in "+target->query_objective()+", and blood pours over your "
       "hands.\n");
   }
   return 1;
} /* do_command() */

       
void do_circle(object doer, object target, int dam){
   object *alist;

   if(sizeof((alist = target->query_attacker_list())) < 2){
      tell_object(doer, "There isn't anyone to distract your victim "
       "long enough for you to circle round.\n");
      return ;
   }
   setup_hb_command(doer,3+random(3),({target,doer->query_hp(),dam}));

   tell_object(doer,"You begin to edge around "
    +target->query_cap_name()+".\n");
} /* do_circle() */


int hb_command(object doer, mixed params, int time){

   if(!params[0] || environment(doer) != environment(params[0]) ||
      already_attacking(doer, params[0]) != 1){

      tell_object(doer, "Your victim seems to have left.  Let the chase "
       "begin!\n");
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(doer->query_dead() || params[0]->query_dead()){
      tell_object(doer, "You stop trying to circle your victim.\n");
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(doer->query_hp() != params[1] ||
      params[0]->query_attackee() == doer ||
      random(100) > 50+doer->query_level()+doer->query_dex() -
      params[0]->query_level()){

      tell_object(doer, "Oh bugger. "+params[0]->query_cap_name()+
       " seems to have noticed your intentions.\n");
      tell_object(params[0], "Just in time you notice "+
       doer->query_cap_name()+" trying to slip around behind you!\n");

      params[0]->attack_by(doer);
      params[0]->set_concentrate(doer);
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(!command_cost(4,doer)){
      tell_object(doer, "You lose your patience..\nIn your haste you "
       "stumble and "+params[0]->query_cap_name()+" notices you!\n");
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(time != 1){
      tell_object(doer, "You continue to work your way behind "+
      params[0]->query_cap_name()+"..\n");
      return 0;
   }

   command_damage(-params[2], doer, params[0]);

   tell_object(doer, "Seizing the moment, you plunge your weapon into "+
    params[0]->query_cap_name()+"'s back.\n"+
    params[0]->query_cap_name()+" spasms in pain.\n");
   tell_object(params[0], "You spasm in pain as "+doer->query_cap_name()+
    " plunges a long sharp object into your back.\nYou could have "
    "sworn "+doer->query_pronoun()+" was in front of you!\n");
   tell_room(environment(doer), doer->query_cap_name()+" circles behind "+
    params[0]->query_cap_name()+" and backstabs "+
    params[0]->query_objective()+".\n",
    ({ params[0], doer }) );
   params[0]->set_concentrate(doer);
   return 1;
} /* hb_command() */

int sense_check(object doer,object target){
   int sense;
   int moi;

   if(!doer->query_hide_shadow())
      return 1;  // Sensed if not hidden
                
   if(target->query_property("sense_life"))
      return 1;
        
   if(target->query_int() > target->query_wis() ) 
      sense = target->query_int();
   else 
      sense = target->query_wis();
   
   sense += target->query_level();

   moi = doer->query_level() + doer->query_dex();

   sense = random(sense); // Always SOME chance of being hit
        
   if (moi < sense)
      return 1;  // You're sensed
   return 0;
} /* sense_check() */

int backstab_damage(object doer,object target, object weapon){
   int lvl;
   int dam;

   lvl = doer->query_level();
   dam = doer->query_dex();
/*
  if (dam>20) dam = 20; // hmm, anyone out there with super dex?
                        // Well, it won't help them, he he
 * Yes it will, Wonderflug
 */

   dam += weapon->query_damage_roll();
   if(lvl < 15)
      dam *= (2 + lvl/2);
   else
      dam *= (5 + lvl/3);
   
   dam /= 10;
   dam += random(dam);  // Backstab surely needs random element    
  // Baldrick's cap to max hp
   if (dam > doer->query_max_hp())
      dam = doer->query_max_hp();
   return(dam);
} /* backstab_damage() */


