// Noble. Gestur 19-6-97.

#include "path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("noble");
   set_short("noble");
   set_al(-100);
   set_gender(random(2));
   set_main_plural("nobles");
   add_alias("human");
   add_alias("humano");
   add_plural("humanos");
   set_race_ob("humano");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   add_move_zone("anduar");
   set_random_stats(10, 14);
   set_level(2+random(3));   
   set_long("Es un noble. Por su vestimenta deduces que es una persona rica. "
            "Parece estar buscando algun objeto por todos lados.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Disculpe caballero por un casual no habreis visto mi montura?",
            1, ":busca algo.",
       }));
       
   adjust_money(random(5), "platinum");
   add_clone("/baseobs/armours/cape",1);
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
   ::attack_by(atacante);
}/*attack_by*/
