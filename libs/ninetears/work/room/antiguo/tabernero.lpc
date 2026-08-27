// Bandido. Gestur 8-10-97

inherit "/obj/monster";

void setup()
{
   set_name("tabernero");
   set_short("Armandin");
   add_alias("armandin");
   add_alias("tabernero");
   add_alias("chigrero");
   set_al(1900);
   set_gender(1);
   set_main_plural("taberneros");
   add_plural("taberneros");
   set_random_stats(12,17);
   set_cha(12+random(5));
   set_guild_ob("/d/gremios/picaros/ladron");
   set_race_ob("/std/races/human");
   set_long("Es un bandido de los muchos que se pueden encontrar en esta "
            "zona. Se gana la vida sirviendo comidas a los viajeros hambrientos "            
	    "que se acercan por estas tierras en busca de fama y fortuna emboscadas.\n");
   add_clone("/baseobs/weapons/daga", 2);
   add_clone("/baseobs/armours/leather", 1);
   adjust_money(random(30), "silver");
  init_equip();
}

