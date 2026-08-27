/* File upgrade by Grimbrand 2-11-96                                    */

inherit "/obj/monster";

void setup() {
   set_name("vieja");
   set_short("vieja");
   set_long("   Esta vieja duergar aparenta ser tan vieja como la "
            "cocina en la que trabaja.  Dicen de ella que empezo "
            "a cocinar aqui desde su apertura, sirviendo desde "
            "entonces a todos los jovenes duergar que se entrenan "
            "en la academia, y alimentadoles bien."
	    "\n\n");
   add_alias("vieja");
   set_race("duergar");
   set_gender(2);
   set_random_stats(6, 18);
   set_max_hp(200);
   set_kill_xp(100);
   set_guild("fighter");
   set_level(22);
   set_al(-150);
  load_chat(30, ({
     1,"' Anda entra y come algo.",
     1,"' Tomate un tazon de buen estofado.",
     1,"' No olvides cerrar el horno jovencito!!",
  }));
  load_a_chat(60,  ({
     1, "' Que gran desafio atacar a una pobre vieja!",
     1, ":te golpea en la cabeza con una barra de pan.",
     1, ":te golpea en el ojo con su baston.",
     1, ":te abofetea en la cara.",
     1, ":te muerde con los 4 dientes que le quedan."
  }));
}
