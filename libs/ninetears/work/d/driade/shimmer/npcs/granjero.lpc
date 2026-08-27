/* Shimmer 2002 */


#define CREATOR "shimmer"

#include "../path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("orco");
   set_short("orco");
   set_al(-100);
   set_gender(1);
   set_main_plural("orcos");
   add_alias("orco");
   add_alias("orco");
   add_plural("orcos");
   set_race_ob("/std/races/orco");
   set_wimpy(0);
   set_random_stats(12, 16);
   set_cha(12+random(5));
   set_level(3+random(5));
   set_long("Es un orco normal y corriente, por lo visto va a ingresar"
            " sus beneficios.\n");
            
   set_aggressive(0);
   load_chat(15,
      ({
            1, "'Media hora esperando! A ver si apuran un poco.",
            1, "'Esperemos que no se ponga a llover."
       }));
   
   adjust_money(random(40), "silver");    
       

   ::init_equip();

}

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_zhyrkh", 1, 300);
   ::attack_by(atacante);
}
