inherit "/obj/monster";

void setup(){
set_name("willy");
set_short("Willy, cuidador del %^GREEN%^Bosque%^RESET%^");
set_long(query_short()+"\nVes a Willy un elfo anciano cuidador del bosque tralak, Willy desde pequenyo se dedico a cuidar, explorar y descubrir los secretos de este bosque, incluso dicen que el fue victima del temible Laren el lagarto gigante y que tambien vio la victoria del gran Drakzten contra Laren. Willy sabe muchos secretos, deberias quedarte un momento a oir sus aventuras.\n\n");
add_alias("elfo");
add_alias("willy");
add_alias("cuidador");
add_alias("anciano");
set_race("elfo");
set_gender(1);
set_level(25+random(5));
set_random_stats(14, 17);
set_wis(18);
set_wimpy(0);
load_chat(60,({
2, "'Hola viajero! bienvenido al bosque tralak, si quieres puedes quedarte un momento aqui y escuchar mis aventuras!.",
2, "'Si.. si.... recuerdo exactamente ese dia... cuando Drakzten vencio al temible Laren, fue una batalla espectacular!.",
4, "'Pero hay algo que me tiene preocupado... dicen que despues de la batalla... quedaron restos del temible Laren...",
2, "'Como dicen todos este bosque tiene muchos misterios y secretos, pero lo mas curioso es que en el centro del bosque hay un arbol de tronco amarillo.",
2, "'Deberias pasar por el pueblo, quizas la gente de alli tambien te ayude.",}));
load_a_chat(80,({
	4, "'Defendere este bosque aunque me cueste la vida!!!.",
	4, "'Quizaz mi apariencia de anciano me haga ver debil, pero estas muy equivocado!!.",}));
add_clone("/baseobs/armas/daga",1);
add_clone("/baseobs/armaduras/armadura_acolchada",1);
	
	init_equip();
	adjust_money(10,"platino");
	
		}