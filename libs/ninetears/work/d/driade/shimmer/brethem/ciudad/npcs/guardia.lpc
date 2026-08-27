/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup() { 

      set_name("Guardia de Brethem");
      set_short("Guardia de Brethem");
      set_main_plural("Guardias de Brethem");
      add_alias("guardia");
      add_plural("guardias");
      set_long("Es un guardia de la ciudad de Brethem, su cometido es vigilas tanto las cercanias de la ciudad "
               "como el interior de la misma, intentando evitar los posibles altercados que puedan sucederse. "
               "No dudara en atacar al minimo sintoma de peligro.\n");
      add_move_zone("brethem");
      set_race_ob("/std/races/human");      
      set_race("human");
      set_gender(1);
      set_max_hp(400);
      set_hp(300);
      set_max_gp(300);
      set_gp(300);
      set_random_stats(20, 22);      
      set_level(25+random(10));
      set_wimpy(0);
      set_al(-100+random(201));
      adjust_money(10+random(5), "gold");
      set_guild("fighther");
  //    set_guild_ob("/std/guilds/warriors/fighter");      
      load_chat(30,
         ({
               1, "@sonrrie al verte llegar.",
               1, "'En esta ciudad no queremos altercados, asi que es mejor que dejes quietas tus armas. ",
               1, "'Estoy aqui para vigilar la ciudad.",
               1, "'No me importa de que raza seas, en esta ciudad yo velo por la seguridad de todos. ",
               1, "'Me encantaria irme a la Taberna del Refugio a tomar algo, pero estoy de guardia, es una pena."
          }));
    
   add_clone(BRETHEM+"equipo/espada_bastarda",1);
   add_clone(BRETHEM+"equipo/yelmo",1);
   add_clone(BRETHEM+"equipo/guanteletes",1);
   add_clone(BRETHEM+"equipo/capa",1);
   add_clone(BRETHEM+"equipo/cota_malla",1);
   ::init_equip();

}

int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   return 0;

}



/* Si atacas a otro guardia o a algun tendero de la ciudad los guardias te daran palos */ 

void event_enter(object ob, string mess, string mensaje, object donde)
{

if ((int)ob->query_timed_property("guardias_brethem"))
   {
      if (ob->query_dead())
      {
         do_command("speak common");
         do_command("'Ya tienes lo que querias?, y la proxima vez tu muerte sera lenta y dolorosa, me he "
                    "quedado con tu cara...");
         ob->remove_timed_property("guardias_brethem");
      }
      else
      {
 this_object()->attack_ob(ob); 
         do_command("speak common");
         do_command("say Eh, tu! no quiero peleas en la ciudad !! Lo pagaras con tu vida  !!!!!!.\n");
      }
   }
   
if ((int)ob->query_timed_property("arbol_milenario"))
   {
      if (ob->query_dead())
      {
         do_command("speak common");
         do_command("'Que?, aun te quedan ganas de juga con el arbolito??");
         ob->remove_timed_property("arbol_milenario");
      }
      else
      {
         this_object()->attack_ob(ob); 
         do_command("speak common");
         do_command("say Como osas maltratar al simbolo de la ciudad !! Te vas a enterar desgraciado  !!!!!!.\n");
      }
   }

   ::event_enter(ob, mensaje, donde);

}


void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_brethem", 1, 300);
   ::attack_by(atacante);
}     

//**************************************************

int adjust_hp(int i, object hp_remover,mixed type) 
{
 if(hp_remover && hp_remover != TO) 
 	{
	tell_object(hp_remover,"HACES %^BOLD%^WHITE%^"+save_variable(i)+"%^RESET%^ PVS DE DANYO.\n");
 	tell_room(this_object(),hp_remover->query_cap_name()+" hace %^BOLD%^YELLOW%^"+ save_variable(i)+" %^RESET%^Pvs de danyo.\n",hp_remover);
	}
return ::adjust_hp(i,hp_remover,type);
}

