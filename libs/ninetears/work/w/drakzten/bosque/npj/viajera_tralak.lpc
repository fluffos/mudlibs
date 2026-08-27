inherit "/obj/monster";

void setup(){
set_name("viajera");
set_short("Viajera");
set_long(query_short()+"\nVes a una sucia y amigable viajera, que quizaz pasa por este infinito bosque para poder llegar al pueblo, pero al al mirar su cara notas su preocupacion, creo que esta perdida.\n\n");
add_alias("humano");
add_alias("viajera");
add_plural("viajeras");
set_race("humano");
set_gender(2);
set_level(8+random(2));
set_random_stats(10, 14);
set_con(15);
set_wimpy(0);
load_chat(60,({
2, "'Uff que gigante es este bosque, parece infinito!.",
2, ":se sequa el sudor de su frente.",
4, "'Sabes a que direccion esta el pueblo?.",}));
load_a_chat(80,({
	4, "'Noooo, estoy demasiado cansado como para una batalla.",}));
add_clone("/baseobs/armas/baston",1);
add_clone("/baseobs/armaduras/capa",1);
	
	init_equip();
	adjust_money(2+random(3),"plata");
	
		}