// Thalos 11-8-97
//Tendero

#include "../../../path.h"
inherit "/obj/civil";

void setup() {
//      object objeto;
      set_name("Dabad-Dinal");
      set_short("Dabad-Dinal el armero");
      set_al(250);
      set_gender(1);
      set_main_plural("varios hombres parecidos a Dabad-Dinal");
      add_alias("dabad-dinal");
      add_alias("tendero");
      add_plural("tenderos");
      add_alias("armero");
      add_plural("armeros");
      set_race_ob("/std/races/duergar");
      set_level(25+random(5));
      set_wimpy(10);
      set_random_stats(12, 18);
      set_long("Es el duergar propietario de la tienda de armas, de la cual se siente orgulloso ya que sabe que es dificil encontrar armas de mayor calidad en cualquier otro luegar de los reinos, anda de aqui por alla atendiendo a los clientes y limpiando cualquier resto de suciedad que esto puedan dejar encima de sus preciadas armas, se comenta que en su trastienda guarda armas dignas de reyes.\n");
      set_aggressive(0);
      adjust_money(random(100), "plata");



      ::init_equip();
}


void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keeron", 1, 600);
   return ::attack_by(atacante);
}
