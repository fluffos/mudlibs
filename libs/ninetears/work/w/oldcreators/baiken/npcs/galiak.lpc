/* 
 * Galiak, el viejo ladron. *
 * Oskuro, 8/1/98           *
 */

inherit "/obj/monster";

void setup()
{
      set_name("galiak");
      set_short("Galiak");
      set_long("Galiak te mira con sus arrugados ojos y esboza una leve "
	       "sonrisa. Es un halfling viejo, con cara de bonachon. En su "
	       "juventud fue uno de los miticos Grandes Ladrones, y a pesar "
	       "del gesto agradable que tiene ahora, fue uno de los "
	       "adversarios mas temidos por muchos guerreros. Se hizo "
	       "famoso por su habilidad con las dagas cortas, las cuales "
	       "clavaba implacablemente en la espalda del adversario sin "
	       "apenas dejar que su rival se diese cuenta. Ahora descansa "
	       "en el Guild, instruyendo a los mas jovenes en las artes "
	       "del hurto y el ataque por sorpresa.\n");
      add_alias("halfling");
      add_alias("dependiente");
      add_alias("viejo");
      set_al(0);
      set_main_plural("Galiaks");
      add_plural("Galiaks");
      set_race("halfling");
      set_language("common");
      set_wimpy(0);
      set_guild_ob("/std/guilds/rogues/thief");
      set_gender(1);
      set_random_stats(14, 18);
      set_cha(18);
      set_dex(20);
      adjust_money(20+random(10),"platinum");
      set_aggressive(0);
      set_level(70+random(15));
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
   add_clone("/baseobs/weapons/dagger",2);
   add_clone("/baseobs/armours/cape",1);
      set_join_fight_mess("Galiak saca una daga de su funda y pone los ojos "
	    "en tu espalda.\n");
      this_object()->init_equip();

} /* setup() */

/*void init()
{
   ::init();
   add_attack_spell(50, "backstab", 
   ({"/std/commands/backstab", 1}));
}

*/
