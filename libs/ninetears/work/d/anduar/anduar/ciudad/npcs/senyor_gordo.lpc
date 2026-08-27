// Ciudadano de Anduar. Gestur'97.

#include  "path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("senyor gordo");
   set_short("senyor gordo");
   set_al(-1000);
   set_gender(1);
   add_alias("senyor");
   set_main_plural("senyores gordos");
   add_alias("human");
   add_alias("humano");
   add_alias("gordo");
   add_plural("senyores");
   add_plural("gordos");
   add_plural("humanos");
   set_race_ob("/std/races/human");
   set_level(1+random(3));
   //set_thac0(100+random(10));
   set_wimpy(0);
   set_random_stats(10, 14);
   set_cha(10+random(4));
   adjust_money(random(6), "gold");
      
   set_long("Es un senyor que por lo visto no hace mucho deporte. Esta en "
            "la cola del banco esperando ser atendido.\n");
            
   set_aggressive(0);
   load_chat(50,
      ({
            1, "'Oiga, no me tocaba a mi ahora?",
            1, "'Por favor, que lo mio es muy poco.",
            1, ":susurra algo en voz baja.",
       }));
   
   add_clone("/baseobs/armours/cape",1);
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_anduar", 1, 100);
   ::attack_by(atacante);
}/*attack_by*/
