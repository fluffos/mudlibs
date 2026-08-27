/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("noble");
   set_short("noble");
   set_al(-100);
   set_gender(0);
   set_main_plural("nobles");
   add_alias("noble");
   add_alias("humano");
   add_plural("nobles");
   set_race_ob("/std/races/human");      
   set_race("humano");
   set_wimpy(0);
   set_random_stats(10, 14);
   set_level(2+random(3));   
   set_long("Es un noble adinerado. Va bien vestido y arreglado y su educacion es exquisita.\n");
            
   set_aggressive(0);
   do_command("speak common");
   load_chat(30,
      ({
            1, "'Saludos buena persona, hace un buen dia hoy, verdad?",
            1, ":te hace una reverencia al verte.",
       }));
       
   adjust_money(random(5), "platinum");
//   add_clone("/baseobs/armours/cape",1);
//   ::init_equip();
}

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_brethem", 1, 300);
   ::attack_by(atacante);
}
