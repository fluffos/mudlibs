// Guardian del Real Camino de Anduar a Dendara

#include "path.h"

inherit "/obj/monster";

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("guardias_camino"))
   {
      if (ob->query_dead())
      {
         do_command("laugh "+ob->query_cap_name());
         do_command("'Eso te pasa por atacar a nuestros hombres.");
         ob->remove_timed_property("guardias_camino");
      }
      else
      {
         this_object()->attack_ob(ob);
         do_command("say Eh, tu! Bastardo! Fuera de aqui!!!!!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}/*event_enter*/

void setup()
{
   object objeto;
   set_name("guardian");
   set_short("guardian del Real Camino");
   set_al(-150);
   set_gender(1);
   set_main_plural("guardianes del Real Camino");
   add_alias("guardian");
   add_alias("guardia");
   add_plural("guardias");
   add_plural("guardianes");
   add_plural("guardianes del Real Camino");
   add_alias("human");
   set_race_ob("/std/races/human");
   set_race("humano");
   set_guild_ob("/std/guilds/warriors/fighter");
   set_wimpy(0);
   set_random_stats(12, 18);
   set_cha(12+random(6));
   set_con(12+roll(3,2));   
   set_str(19+random(10)); /* Fuerza extrema de los guerreros humanos :) */
                           /* 19 == 18/10 .................. 28 == 18/00 */
   set_level(15+random(10));
   
   set_long("Es un guardian del Real Camino de Anduar a Dendara. Parece "
   "fuerte y disciplinado o sea que no pienses mucho en atacarle. Va fijandose "
   "en la gente que circula por este amplio camino.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Soy uno de los pocos elegidos para guardar este camino real!",
            1, ":se fija en ti.",
            1, "'Tenga cuidado al salir del camino, hay peligrosos "
            "delincuentes",
       }));
       
   add_clone("/baseobs/weapons/long_sword",1);
   add_clone("/baseobs/armours/med_shield",1);
   add_clone("/baseobs/armours/chainmail",1);
   init_equip();
}/*setup*/

void attack_by(object atacante)
{
    atacante->add_timed_property("guardias_camino", 1, 60);
   ::attack_by(atacante);
}/*attack_by*/
