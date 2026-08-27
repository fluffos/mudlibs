// Thalos 11-8-97
//Tendero

#include "../../../path.h"
inherit "/obj/monster";

void setup() {
      set_name("Gabin");
      set_short("Gabin el tendero");
      set_al(250);
      set_gender(1);
      set_main_plural("varios hombres parecidos a Gabin");
      add_alias("gabin");
      add_alias("tendero");
      add_plural("tenderos");
      set_race_ob("/std/races/duergar");
      set_level(25+random(5));
      set_wimpy(10);
      set_random_stats(12, 18);
      set_long("Es el propietario de la tienda de armaduras en la que te encuentras.\n");
      set_aggressive(0);
      adjust_money(random(100), "plata");



      ::init_equip();
}


void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keeron", 1, 600);
   return ::attack_by(atacante);
}
