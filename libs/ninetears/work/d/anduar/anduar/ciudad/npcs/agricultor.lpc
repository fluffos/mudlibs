#include "path.h"

inherit "/obj/monster";

void setup()
{
   set_name("agricultor");
   set_short("agricultor de Anduar");
   set_al(-250);
   set_gender(2);
   set_main_plural("agricultores de Anduar");
   add_alias("human");
   add_alias("humano");
   add_plural("agricultores");
   add_plural("humanos");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   set_random_stats(12, 16);
   set_cha(12+random(5));
   set_level(5+random(10));
   set_long("Parece un agricultor que se dedica a cultivar las diferentes "
   "fincas que bordean Anduar y las cuales son fuente de sustento de la "
   "misma.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Esta cosecha va a ser la mejor desde hace muchos anyos.",
            1, "'Esperemos que el granizo no eche a perder la cosecha."
       }));
   
   adjust_money(random(10), "silver");    
       
   add_clone("/baseobs/weapons/pitchfork",1);
   add_clone("/baseobs/armours/cloak",1);
   add_clone("/baseobs/armours/slippers",1);
   init_equip();
}/*setup*/

