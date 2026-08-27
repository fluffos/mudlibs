
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
   set_command_name("backstab");
   target_type = BACKSTAB_TYPE;
   sec_lockout = BACKSTAB_LOCKOUT;
   sec_lock_prop = BACKSTAB_LOCK_PROP;
   guilds = BACKSTAB_GUILDS;

   set_help_string(
    "Syntax: apunyalar <persona>\n\n"
    "La punyalada es un ataque basado en tu nivel y tu destreza. "
    "Es posible que tu victima detecte la punyalada y la esquive, pero claro, "
    "eso depende de su nivel, su sabiduria y su inteligencia. "
    "Tanto como si la punyalada es satisfactoria como si no lo es, la victima "
    "te atacara.\n\nNecesitas un arma punzante para realizar este ataque, y "
    "es mas que recomendable estar escondido.\nEl coste depende de tu nivel.\n\n"
    "Tambien puedes apunyalar durante una pelea, pero solo si hay alguien que "
    "distraiga a tu victima. En este caso, el ataque cuesta 4 GPs por round.\n\n");

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
      tell_object(doer, "Te encuentras demasiado cansado...\n");
      return 1;
   }

   if(doer->query_level() < 5){
      tell_object(doer,"Te sientes poco habilidoso para apunyalar.\n");
      return 1;
   }
   weap = doer->query_weapons_wielded();
   if(!sizeof(weap)){
      tell_object(doer,"Tus dedos no son lo suficientemente afilados como para "
       "hundirse en la carne de tu victima.\n");
      return 1;
   }

   damage = 0;
   doer->add_property("apunyalando", 1); // Para las armas con bonus al apunyalar. Xerxes '02
   for (i=0;i<sizeof(weap);i++){
      if(weap[i]->query_attack_type() == 3) 
         damage += backstab_damage(doer,target,weap[i]);
      else{
         tell_object(doer,"Es imposible clavarle a alguien tu "+
         weap[i]->query_short()+".\n");
         return 1;
      }
   }
   doer->remove_property("apunyalando", 1); // Para las armas con bonus al apunyalar. Xerxes '02

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
      tell_object(doer, "No seria muy buena idea desatender a tus enemigos "
       "para apunyalar a otra persona.\n");
      return 1;
   }

   doer->add_timed_property(sec_lock_prop,7,sec_lockout);

   if(sense_check(doer,target)){
      tell_object(doer,"Argh! "+tname+" parece haberse dado cuenta de "
       "tus intenciones!\n");
      command_cost(cost/3,doer);
   }
   else {
     // Fake event triggers, for "special" weapons - Radix
      for(i=0; i<sizeof(weap); i++)
         weap[i]->event_backstab(damage,doer,target);
      command_cost(cost,doer);
      command_damage(-damage,doer,target);
      tell_object(target,"Convulsionas agonicamente cuando "+dname+" entierra su "+
       wname+" en tu espalda!\nEso realmente ha dolido!\n");
      tell_room(environment(doer), tname+" convulsiona en agonia "
        "cuando " +dname+ " hunde su "+ wname +
	" en "+target->query_possessive()+" espalda!\n",
       ({ doer, target }) );
   }
   return 1;
} /* do_command() */

void do_circle(object doer, object target, int dam){
   object *alist;

   if(sizeof((alist = target->query_attacker_list())) < 1){
      tell_object(doer, "No hay nadie que pueda distraer a tu victima mientras la rodeas.\n");
      return ;
   }
   setup_hb_command(doer,3+random(3),({target,doer->query_hp(),dam}));

   tell_object(doer,"Empiezas a rodear a "
    +target->query_cap_name()+".\n");
	tell_object(target, "Notas a alguien dando rodeos en el fragor de la batalla.\n");
} /* do_circle() */


int hb_command(object doer, mixed params, int time){

   if(!params[0] || environment(doer) != environment(params[0]) ||
      already_attacking(doer, params[0]) != 1){

      tell_object(doer, "Parece que tu victima se ha ido. Que empiece la "
       "persecucion!\n");
      call_out("end_hb_command", 0, doer);
      return 1;
   }

   if(doer->query_dead() || params[0]->query_dead()){
      tell_object(doer, "Dejas de rodear a tu victima.\n");
      call_out("end_hb_command", 0, doer);
      return 1;
   }

/*      params[0]->query_attackee() == doer ||
   if(doer->query_hp() != params[1] ||*/
   if(random(100) > 80+doer->query_level()+doer->query_dex() -
      params[0]->query_level()){

      tell_object(doer, "Vaya! "+params[0]->query_cap_name()+
       " parece haberse dado cuenta de tus intenciones.\n");
      tell_object(params[0], "Notas a "+
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
   tell_object(params[0], "Unos espasmos de dolor te recorren cuando "+doer->query_cap_name()+
    " agujerea tu espalda con un objeto largo y cortante.\nJurarias que "
    +doer->query_pronoun()+" estaba delante de ti!\n");
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
   
   dam += random(dam);
  // Baldrick's cap to max hp
   if (dam > doer->query_max_hp())
      dam = doer->query_max_hp();
   return(dam);
} /* backstab_damage() */


