/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("concejal");
   set_short("concejal");
   set_al(-100);
   set_gender(random(2));
   set_main_plural("concejales");
   add_alias("concejal");
   add_alias("humano");
   add_alias("hombre");
   add_plural("humanos");
   add_plural("concejales");
   set_race_ob("/std/races/human");
   set_wimpy(10);
   set_random_stats(10, 14);
   set_level(2+random(3));   
   set_long("Es uno de los concejales de Brethem, trabaja en el ayuntamiento en alguna de las distintas "
            "secciones de las que este consta.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Y bien, que le trae por aqui, algun asunto de terrenos?, de herencia?",
            1, ":te saluda educadamente.",
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
