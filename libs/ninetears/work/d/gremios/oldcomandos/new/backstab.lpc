
/*
Converted to base command by
Malik Sept 97
*/
/* many + Taniwha, Manshoon, Baldrick and Wonderflug made this */



inherit "/d/gremios/comandos/base_command";

#include "new_tweaks.h"


int backstab_damage(object doer,object target, object weapon);
void do_circle(object doer, object target, int dam);
int sense_check(object doer, object target);


void setup(){
   set_command_name("apunyalar");
   target_type = BACKSTAB_TYPE;
   sec_lockout = BACKSTAB_LOCKOUT;
   sec_lock_prop = BACKSTAB_LOCK_PROP;
   guilds = BACKSTAB_GUILDS;

   set_help_string(
    "Sintaxis: apunyalar <persona>\n\n"
    "El apunyalar esta basado en tu nivel y destreza. "
    "Tu victima tiene la suerte de notar tu punyalada y evitarla "
    "segun su nivel, sabiduria e inteligencia. "
    "Si tienes exito o no, la victima te atacara.\n\n"
    "Necesitas un arma punzante para ser capaz de apunyalar y debes estar "
    "escondido.\nEl coste en pg depende del nivel.\n\n"
    "Puedes apunyalar durante una lucha, sirvete de algo "
    "que este alli para distraer a tu oponente el rato suficiente "
    "para poder atacarlo por detras.  En este caso el coste es de "
    "4 GP por turno para hacer lo que necesitas.\n\n"
    "Ejemplo\n> apunyalar mercader\n");

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
      tell_object(doer, "Estas demasiado cansado para volver a apunyalar.\n");
      return 1;
   }

   if(doer->query_level() < 10){
      tell_object(doer,"Te encuentras poco habil para apunyalar.\n");
      return 1;
   }
   weap = doer->query_weapons_wielded();
   if(!sizeof(weap)){
      tell_object(doer,"Tus dedos no son lo suficientemente afilados "
       "para apunyalar nada.\n");
      return 1;
   }

   damage = 0;
   for (i=0;i<sizeof(weap);i++){
      if(weap[i]->query_attack_type() == 3) 
         damage += backstab_damage(doer,target,weap[i]);
      else{
         tell_object(doer,"Te seria practicamente imposible usar tu "+
         weap[i]->query_short()+" para ponerte detras.\n");
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
      tell_object(doer, "No seria buena idea descuidar tus otros "
       "atacantes y apunyalar alguno tambien.\n");
      return 1;
   }

   doer->add_timed_property(sec_lock_prop,100,sec_lockout);

   if(sense_check(doer,target)){
      tell_object(doer,"Oh que fallo, "+tname+" parece haber adivinado "
       "tus intenciones!\n");
      command_cost(cost/3,doer);
   }
   else {
     // Fake event triggers, for "special" weapons - Radix
      for(i=0; i<sizeof(weap); i++)
         weap[i]->event_backstab(damage,doer,target);
      command_cost(cost,doer);
      command_damage(-damage,doer,target);
      tell_object(target,"Te convulsionas agonicamente cuando "+dname+" te clava su "+
       wname+" en tu espalda!\nEstas realmente herido!\n");
      tell_room(environment(doer), tname+" se convulsiona agonicamente cuando "+dname+
       " le clava su "+wname+" en su espalda!\n",
       ({ doer, target }) );
      tell_object(doer,tname+" se convulsiona agonicamente cuando le clavas tu "+wname+
       " en su espalda, y la sangre corre a mares por tus "
       "manos.\n");
   }
   return 1;
} /* do_command() */

       
void do_circle(object doer, object target, int dam){
   object *alist;

   if(sizeof((alist = target->query_attacker_list())) < 2){
      tell_object(doer, "No hay nada para distraer a tu victima "
       "lo suficiente para rodearlo.\n");
      return ;
   }
   setup_hb_command(doer,3+random(3),({target,doer->query_hp(),dam}));

   tell_object(doer,"Comienzas a rodearlo "
    +target->query_cap_name()+".\n");
} /* do_circle() */


int hb_command(object doer, mixed params, int time){

   if(!params[0] || environment(doer) != environment(params[0]) ||
      already_attacking(doer, params[0]) != 1){

      tell_object(doer, "Tu victima parece haber salido. Empieza una "
       "nueva caza!\n");
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(doer->query_dead() || params[0]->query_dead()){
      tell_object(doer, "Paras de intentar rodear a tu victima.\n");
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(doer->query_hp() != params[1] ||
      params[0]->query_attackee() == doer ||
      random(100) > 50+doer->query_level()+doer->query_dex() -
      params[0]->query_level()){

      tell_object(doer, "Oh Fallaste. "+params[0]->query_cap_name()+
       " parece haber notado tus intenciones.\n");
      tell_object(params[0], "Justo a tiempo notas a "+
       doer->query_cap_name()+" intentar rodearte para ponerse detras tuyo!\n");

      params[0]->attack_by(doer);
      params[0]->set_concentrate(doer);
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(!command_cost(4,doer)){
      tell_object(doer, "Pierdes la paciencia..\nEn tu ataque "
       "te tambaleas y "+params[0]->query_cap_name()+" te descubre!\n");
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(time != 1){
      tell_object(doer, "Continuas buscando la forma de ponerte detras de "+
      params[0]->query_cap_name()+"..\n");
      return 0;
   }

   command_damage(-params[2], doer, params[0]);

   tell_object(doer, "Esperas el momento, hundes tu arma en la espalda de "+
    params[0]->query_cap_name()+".\n"+
    params[0]->query_cap_name()+" tiene espamos enfermizos.\n");
   tell_object(params[0], "Tienes espasmos enfermizos cuando "+doer->query_cap_name()+
    " te hunde un largo filo en la espalda.\nDeberias tener en "
    "cuenta el tener a "+doer->query_pronoun()+" delante de ti!\n");
   tell_room(environment(doer), doer->query_cap_name()+" rodea por detras a "+
    params[0]->query_cap_name()+" y lo apunyala a traicion.\n",
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


