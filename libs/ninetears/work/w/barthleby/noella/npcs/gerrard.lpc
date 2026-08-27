#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("Gerrard");
   set_short("Lord Gerrard");
   set_al(-100);
   set_gender(1);
   set_main_plural("Lords Gerrard");
   add_plural("gerrards");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   set_random_stats(15, 18);
   set_str(25);
   set_dex(18);
   set_con(18);
   set_cha(15+random(3));
   set_level(20+random(10));
   set_long("Un viejo y fornido caballero que es el actual propietario de la tasca. Su armadura lleva el escudo "
   "familiar y del local. Algunos de los artefactos de guerra de tu alrededor fueron utilizados por el en "
   "antiguas batallas. No suele enfadarse hasta que se enfada, como todos.\n");

   adjust_money(random(100), "silver");
   set_aggressive(0);
   load_chat(50,
      ({
            1, "'Si vienes buscando alcohol y problemas has llegado al lugar adecuado.",
            1, "'tienes cara de querer beber algo. Que deseas?.",
            1, ":se bebe una cerveza.",
            1, "'algo para picar?.",
	    1, ":limpia la barra."
       }));

   objeto=new(ARMA+"baston");
   objeto->move(this_object());
   objeto=new(ARMADURA+"capa");
   objeto->move(this_object());
   TO->init_equip();
}
void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_noella", 1, 300);
   ::attack_by(atacante);
}/*attack_by*/
