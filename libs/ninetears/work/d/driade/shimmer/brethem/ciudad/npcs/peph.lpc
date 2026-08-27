/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("Peph");
      set_short("Peph de Noella");
      set_al(-60);
      set_gender(1);
      set_main_plural("varios hombres parecidos a Peph");
      add_alias("peph");
      add_plural("pephs");
      set_race_ob("/std/races/humano");
      set_level(25+random(5));
      set_wimpy(10);
      set_random_stats(12, 18);
      set_long("Es el propietario de la taberna en la que te encuentras encuentra.\n");
      set_aggressive(0);
      adjust_money(random(100), "silver");



      ::init_equip();
}


void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_brethem", 1, 300);
   return ::attack_by(atacante);
}