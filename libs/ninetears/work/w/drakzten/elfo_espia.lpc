inherit "/obj/moster";

void setup(){

set_name("elfo");
set_short("Elfo espia");
set_long(query_short()+."\n\nSe trata de un joven elfo el cual se oculta en este arbol para"
                            "poder espiar en la noche a los ciudadanos del poblado de Urghak."
                            "Nadien sabe porque los espia, pero al jefe le a molestado su"
                            "presencia y le a puesto precio a su cabeza."\n\n);
set_main_plural("Elfos espias");
set_alias(({"elfo","espia"}));
set_plural(({"elfos","espias"}));
set_gender(1);
set_habilidad("doble arma",50);
set_level(20+random(6));
set_random_stats(13, 16);
set_dex(18);
set_wimpy(0);
set_max_hp(query_level() * 10);
set_hp(query_max_hp());
load_chat(40,({
	1, "'Que estaran asiendo esos goblins ahora...",
	1, ":parece pensativo.",
	2, "'Quien eres tu? que haces aqui?!.",}));
	
load_a_chat(50,({
	2, "'Hace mucho tiempo que no peleaba...",
	1, "'Veras de lo que somos capazes los elfos!!",
	2, ":parece concentrarse mas en ti.",}));
	
add_clone("/baseobs/armas/daga",2);
add_clone("/baseobs/armaduras/cota",1);

init_equip();
adjust_money(14+random(5),"plata");
}