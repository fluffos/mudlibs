/* Shimmer 2002 */


#define CREATOR "shimmer"

#include "../path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("orca");
   set_short("orca");
   set_al(-100);
   set_gender(random(2));
   set_main_plural("orcas");
   add_alias("orca");
   add_alias("orco");
   add_plural("orcos");
   set_race_ob("/std/races/orco");
   set_wimpy(0);
   set_random_stats(10, 14);
   set_level(5+random(3));   
   set_long("Es una mujer orca. Alta y fuerte, parece que esta en la cola esperando su turno como todos.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Cuanto habre obtenido de intereses hoy?",
            1, ":se frota las manos.",
       }));
       
   adjust_money(random(5), "platinum");

   ::init_equip();
}

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_zhyrkh", 1, 300);
   ::attack_by(atacante);
}
