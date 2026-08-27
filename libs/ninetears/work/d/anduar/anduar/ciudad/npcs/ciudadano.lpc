// Ciudadano de Anduar. Gestur'97.
#include "path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("ciudadano");
   set_short("ciudadano");
   set_gender(1);
   set_main_plural("ciudadanos");
   add_plural("ciudadanos");
   add_alias("human");
   add_alias("humano");
   add_plural("humanos");
set_race_ob("Humano");
   set_race_ob("/std/races/human");
   set_al(-750);
   set_wimpy(25);
   set_random_stats(10, 14);
   set_cha(10+random(4));
   set_level(2+random(5));     
   set_long("Es un ciudadano pacifico de Anduar, parece que esta dando un "
            "paseo por la ciudad.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Buenos dias, senyor",
            1, ":sonrie.",
       }));
       
   add_clone("/baseobs/weapons/dagger",1);
   add_clone("/baseobs/armours/cape",1);
   ::init_equip();
}/*setup*/
