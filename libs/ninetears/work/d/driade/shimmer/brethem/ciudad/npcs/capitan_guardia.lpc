/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup() { 

      set_name("capitan de la guardia");
      set_short("Capitan de la Guardia");
      set_main_plural("Capitanes de la Guardia");
      add_alias("guardia");
      add_alias("guardian");
      add_alias("capitan");
      add_plural("guardias");
      add_plural("guardianes");
      add_plural("capitanes");
      set_long("Es uno de los capitanes de la guardia de la ciudad de Brethem, daria su vida por defender la ciudad "
               "y esta entrenado en el arte de la guerra, es un gran guerrero. No dudara en defender Brethem al minimo "
               "sintoma de peligro.\n");
      add_move_zone("brethem");
      set_race_ob("/std/races/human");      
      set_race("human");
      set_gender(1);
      set_max_hp(400);
      set_hp(400);
      set_max_gp(300);
      set_gp(300);
      set_random_stats(20, 22);      
      set_level(51+random(10));
      set_wimpy(0);
      set_al(-100+random(201));
      adjust_money(10+random(5), "gold");
      set_guild("fighther");
//      set_guild_ob("/std/guilds/warriors/fighter");      
      load_chat(30,
         ({
               1, "@sonrie al verte llegar.",
               1, "'El que ataco la ciudad esta muerto, no escapara de nuestra vista, me quede con su fea cara!. ",
               1, "'Estoy aqui para vigilar la ciudad.",
               1, "'No me importa de que raza seas, en esta ciudad yo velo por la seguridad de todos. ",
               1, "'Me encantaria irme a la Taberna del Refugio a tomar algo, pero estoy de guardia, es una pena."
          }));
    
   add_clone(BRETHEM+"equipo/espada_bastarda",1);
   add_clone(BRETHEM+"equipo/yelmo",1);
   add_clone(BRETHEM+"equipo/guanteletes",1);
   add_clone(BRETHEM+"equipo/capa",1);
   add_clone(BRETHEM+"equipo/cota_malla",1);
   ::init_equip();

}

