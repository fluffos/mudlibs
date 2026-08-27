/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup() {
      set_name("enterrador");
      set_race_ob("/std/races/human");

      set_main_plural("enterradores");
      add_plural("enterradores");

      set_al(10);
      set_random_stats(6, 17);
      set_cha(6+random(10));
      set_level(5+random(2));
      set_wimpy(10);
      adjust_money(random(10),"silver");
      set_short("enterrador");
      set_long("Enterrador\n\nEs uno de los enterradores del cementerio de Brethem, esta completamente "
               "sucio y lleno de tierra.\n");
      load_chat(50, ({ 
         1, "'Que le trae por este lugubre cementerio?.", 
         1, "'Ultimamente no paramos, muere gente a todas horas, a ver si dejais de xpear en la ciudad...",
         1, "'No moleste a los que yacen en las tumbas, no es bueno romper su eterno descanso.",
         1, ":se echa la pala al hombro y te mira de arriba abajo."}));

      add_clone(BRETHEM + "equipo/pala",1);
      add_clone(BRETHEM + "equipo/capa",1);

      ::init_equip();

      add_move_zone("brethem");

} 