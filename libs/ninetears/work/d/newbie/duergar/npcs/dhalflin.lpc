/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("halfling");
   add_alias("cautiva");
   add_alias("Cautiva");
   set_short("Halfling Cautiva");
   set_long("   Una inteligente halfling. Es de pequenyo tamanyo, "
            "como es normal entre ellos, y la han traido aqui para "
            "ser muerta a manos de aprendices duergar. Su manera "
            "indolente de contemplarte te hace hervir la sangre."
	    "\n\n");
   set_main_plural("Cautivas");
   set_gender(2);
   set_race("halfling");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(random(30), "cobre");
 
  load_chat(30,({
     1, "' Solo soy una inocente criatura indefensa, dejame ir por favor.",
     1, "' Malditos duergar,no nos dejaran en paz mientras quede uno.",
 
  }));
 
  load_a_chat(25, ({
     1, ":da una voltereta y esquiva tu ataque.",
     1, "'Anda vamos, dame una razon para temerte.",
     1, ":te escupe a los pies.",
     1,"'No pienso morir en un sitio tan nauseabundo.",
 
  }));
}
