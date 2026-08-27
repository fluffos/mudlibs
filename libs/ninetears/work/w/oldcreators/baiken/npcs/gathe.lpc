/* Nair el 'portero' de Gremio de Ladrones */
inherit "/obj/monster";

void setup()
{
      set_name("gathe");
      set_short("Gathe");
      set_long("Gathe es una de las subordinadas de Helrek mas poderosas. "
               "Aun siendo humana, es una de las ladronas mas veneradas, "
               "mas por sus artes y habilidades en el hurto que por ser "
               "una sangrineta asesina. Helrek, su Maestro le encomienda "
               "la mision de saquear a todo aquel que se acerca a la "
               "Guarida de los Ladrones, pero si alguien ajeno intenta "
               "acceder, tambien es su mision proteger la entrada.\n"
               "A juzgar por los musculos marcados en su carne rosada, "
               "nadie querria enfrentarse a sus espadas cortas. "
               "Los lugarenyos recomiendan no dejarse llevar por el "
               "encanto de Gathe, es su arma preferida...\n");
      add_alias("guardiana");
      set_al(400);
      set_main_plural("Gathes");
      add_plural("Gathes");
      set_race("Humano");
      set_race_ob("/std/races/human");
      set_language("common");
      set_wimpy(0);
      set_guild_ob("/std/guilds/rogues/thief");
      set_gender(2);
      set_random_stats(14, 18);
      set_cha(25);
      set_dex(22);
      adjust_money(5+random(5),"gold");
      set_aggressive(0);
      set_level(70+random(15));
/*
      load_chat(30,
	 ({
	       1, "'Hola, bienvenido a mi tienda.",
	       1, "'Hay un amplio surtido de dagas y objetos punzantes.",
	       1, "'Todavia recuerdo como me excitaba mojarme con la sangre "
		   "de una victima cuando la apunyalaba.",
	       1, "'En estos tiempos, el dominio del arte de la punyalada "
		   "es tan importante como llevar una buena armadura.",
	       1, "'No traes la armadura enrojecida. Sal ahi afuera y "
		   "manchala.",
	       1, ":se distrae afilando una ganzua.",
	       1, ":pasa el tiempo limpiando sus viejas ganzuas.",
               1, ":afila una de sus antiguas dagas magicas.",
               1, "'Algun dia te contare la Leyenda de los Grandes Ladrones.",
	  }));

      load_a_chat(65,
	 ({
	       1, "'No sabes lo que me divierte luchar!",
	       1, "'Los cobardes como tu caen facilmente bajo el poder de "
	          "mi Daga...",
	       1, "'No mereces pertenecer a este guild!! Ahora veras!",
	       1, "'No vas a salirte con la tuya, joven ladronzuelo!",
	       1, ":te mira con sus ojos llenos de rabia.",
	       1, "'Si supieses quien fui en el Pasado, no habrias hecho "
	          "esto.",
	  }));
*/
      add_clone("/baseobs/weapons/short_sword",2);
      add_clone("/baseobs/armours/cape",1);
      add_clone("/baseobs/armours/studded",1);
      add_clone("/baseobs/armours/cowl",1);
      set_join_fight_mess("Gathe enfurece y se lantha contra ti.\n");
      ::init_equip();

}

/*void init()
{
   ::init();
   add_attack_spell(50, "backstab", 
   ({"/std/commands/backstab", 1}));
}

*/
