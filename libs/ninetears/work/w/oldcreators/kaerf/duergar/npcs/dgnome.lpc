/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("gnoma");
   add_alias("cautiva");
   add_alias("Cautiva");
   set_short("Gnoma Cautiva");
   set_long("   Es una pequenya y peluda gnoma.  Capturada en algun "
            "poblado de superficie durante la ultima incursion de los "
            "expedicionarios duergar. Se mueve nerviosa por el cuarto, "
            " al verte te mira llena de odio y tantea buscando un arma."
	    "\n\n");
   set_main_plural("Cautivas");
   set_gender(2);
   set_race("gnome");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(1,"oro");
 
  add_language("comun");
  do_command("speak comun");
  load_chat(30,({
     1, ":penetra tu alma con su mirada llena de odio.",
     1, "' Los duergar tendran que esmerarse mas si quieren afectar mi animo.",
  }));
 
  load_a_chat(25, ({
     1, "'JA! te parece que eres lo bastante grande para pelear conmigo?",
     1,"'Te mostrare como pelear con destreza, pato gordo!",
 
  }));
}
