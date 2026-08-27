#include "path.h"

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("dimsdale");
      set_short("Dimsdale el chupatintas");
      set_long("Dimsdale es el tipico humano que se entrega totalmente a "
      "su trabajo: delgado, esmirriado, con ojeras... Solo vive por su "
      "trabajo. Este humano de avanzada edad no podria vencer a casi nadie "
      "en una lucha, pero seguro que trabaja mas eficientemente en su "
      "trabajo que nadie.\n");
      set_al(-100);
      set_gender(1);
      set_main_plural("chupatintas");
      add_alias("human");
      set_race_ob("/std/races/human");
      set_wimpy(10);
      set_random_stats(12, 14);
      set_cha(12+random(2));
      set_level(5+random(5));
      adjust_money(random(30), "platinum");
      set_aggressive(0);
      load_a_chat(50,
      ({ 1, "'Consigues iniciar un trabajo honrado y pasa esto!!",
         1, "'Argh, eso duele, asesino!!",
         }));
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
   return ::attack_by(atacante);
}
