inherit "/obj/monster";

void setup(){
set_name("viajero");
set_short("Viajero");
set_long(query_short()+"\nVes a un sucio y amigable viajero, que quizaz pasa por este infinito bosque para poder llegar al pueblo, pero al al mirar su cara notas su preocupacion, creo que esta perdido.\n\n");
add_alias("humano");
set_main_plural("Viajeros");
add_alias("viajero");
add_plural("viajeros");
set_race("humano");
set_gender(1);
set_level(8+random(5));
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