// Vilat 29.10.2002
// Tabernero base
inherit "/obj/monster";

void setup() {
      	set_name("dependiente");
      	set_short("Dependiente");
      	add_alias("tabernero");
	add_alias("cocinero");
	add_alias("chulo");
      	set_main_plural("Dependientes");
      	add_plural("taberneros");
	add_plural("dependientes");
	add_plural("cocineros");
	add_plural("chulos");
	set_gender(1);
      	set_level(11+random(10));
      	set_wimpy(0);
	add_clone("/w/aprendizaje/jamonero",1);
	init_equip();
      	set_random_stats(14, 20);
      	set_long(query_short()+"\nEl dependiente del local, el solo hace las funciones de recepcionista, tabernero, cocinero e incluso chulo de putas si asi se tercia.\n");
      	adjust_money(random(300), "cobre");
      	load_chat(30, ({
               	1, ":remueve el puchero.",
		1, "'Que vas a tomar?",
		2, ":se rasca el trasero.",
          	}));
	}
