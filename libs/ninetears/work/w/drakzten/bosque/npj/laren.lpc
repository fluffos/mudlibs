inherit "/obj/monster";

void setup(){
set_name("laren");
set_short("%^GREEN%^Laren, el lagarto gigante%^RESET%^");
set_long(query_short()+"\nVes a la bestia mas temible que hayas visto en tu vida, se trata de un lagarto gigante de unos 10 metros de altura y una cola de unos 8 metros de largo, tiene unos grandes ojos rojos los cuales no te quitan la mirada de encima, su piel es escamosa y muy gruesa, pero te das cuenta que le faltan algunos trozos de carne en el cuerpo, creo que este fue el resto que quedo de la gran batalla de Drakzten contra Laren. Parece que lo han resucitado.\n\n");
add_alias("zombie");
add_alias("lagarto");
add_alias("laren");
add_alias("gigante");
set_gender(1);
set_level(70+random(5));
set_random_stats(20, 25);
set_int(1);
set_wimpy(0);
set_max_hp(query_level() * 100);
set_hp(query_max_hp());
set_max_gp(query_level() * 30);
set_gp(query_max_gp());

load_chat(30,({
1, ":agita su cola de un lado para otro.",}));
load_a_chat(80,({
	4, ":comienza a mirar fijamente mientras sus ojos estallan en colera.",
	1, "'Phsss.",}));
	
	}
	void event_enter(object enemigo, string puta, mixed putah) {
		enemigo->attack_by(TO);
		::event_enter(enemigo,puta,putah);
		}