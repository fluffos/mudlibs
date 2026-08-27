// Gareth 24.11.02

inherit "/obj/monster";
#include "/d/gremios/path.h"

void setup()
{	set_name("guardia");
  	set_short("Guardia Khurgar");
  	set_long("Un pequenyo aunque corpulento duergar, guardian del gremio. "
  	"Tiene una mirada profunda, de ojos grises. El yelmo solo te permite ver "
  	"una barba que le llega hasta la cintura, separada en dos trenzas. "
  	"Va vestido con una cota de malla, y unas botas de cuero.\n");
	set_main_plural("guardias");
  	add_alias("guardia");
  	add_alias("guardian");
  	add_plural("guardianes");
  	set_random_stats(17,20);
  	set_level(20);
  	set_race("duergar");
  	set_language("common");
  	set_gender(1);
  	set_max_hp(query_level() * 50);
      	set_hp(query_max_hp());
      	set_max_gp(query_level() * 60);
      	set_gp(query_max_gp());
	set_max_ep(query_level() * 20);
      	set_gp(query_max_ep());
  	set_join_fight_mess("Guardia Duergar dice: no permitire que pases!!.\n");
  	
  	add_property("NO_BUDGE",1);
  	add_property("nosteal",1);
  	
  	load_chat(10,
({		2, ":le saca brillo a su hacha.",
		1, ":se arregla la barba.",
		1, ":se mantiene firme, vigilando la entrada.",
		2, ":camina de un lado para otro.",
}));
  	
  	load_a_chat(80,
({		1, "'tu osadia sera castigada!",
		1, "'no saldras vivo de esta!!",
		1, "'fuera de aqui!",
}));
	add_clone("/baseobs/armas/hacha_de_batalla",1);
	add_clone("/baseobs/armaduras/cota_reforzada",1);
	add_clone("/baseobs/armaduras/yelmo_grande",1);  
	init_equip();
}

void init() {
	::init();
	add_attack_command(15, "furia", "/comandos/khurgar/furia","furia",0);
	add_attack_command(20, "cabezazo", "/comandos/khurgar/cabezazo","cabezazo",0);
	}