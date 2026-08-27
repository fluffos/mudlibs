inherit "/obj/monster";

void setup(){
set_name("aventurero");
set_short("Aventurero");
set_long(query_short()+"\nVes a un valiente y curioso aventurero el cual le gusta hacer incurciones por los bosques y ver los monumentos mas impresionantes que aya visto en su vida.\n\n");
add_alias("humano");
add_alias("aventurero");
add_plural("aventureros");
set_race("humano");
set_gender(1);
set_level(11+random(2));
set_random_stats(11, 15);
set_con(15);
set_wimpy(0);
load_chat(60,({
2, "'Me encanta vivir aventuras.",
2, "'Has visto el arbol de tronco amarillo? dicen que esta en este bosque pero no lo encuentro.",
4, "'Este bosque es muy grande, exelente para un aventurero como yo.",}));
load_a_chat(80,({
	4, "'Que bien una batalla, ya hacia tiempo que no luchaba.",
	2, ":sonrie agradablemente."}));
add_clone("/baseobs/armas/espada_larga",1);
add_clone("/baseobs/armaduras/armadura_de_cuero",1);
	
	init_equip();
	adjust_money(3+random(3),"oro");
	
		}