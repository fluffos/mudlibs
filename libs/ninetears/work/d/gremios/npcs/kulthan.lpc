//Gareth 7.12.02

#include "/d/gremios/path.h"
inherit "/obj/monster";

void setup() {
	set_name("kulthan");
	set_short("Kulthan");
		set_long("    Un fornido duergar, muy alto en proporcion a los demas de su raza."
		 "Es uno de los mejores herreros de Driade, famoso sobre todo porque"
		 " sus hachas son las de mejor calidad. El sudor producido por el "
		 "calor de la fragua cubre su musculoso cuerpo, cubierto por una tunica.\n\n");
	set_main_plural("herreros");
	add_alias("kulthan");
  	add_alias("herrero");
  	set_race("duergar");
  	set_language("common");
	set_gender(1);
	set_level(50+random(25));
	set_wimpy(0);
	set_max_hp(query_level() * 40);
	set_hp(query_max_hp());
	set_max_gp(query_level() * 50);
	set_gp(query_max_gp());
	set_random_stats(16, 18);

  	add_property("NO_BUDGE",1);
  	add_property("nosteal",1);

	load_chat(15,
        ({
               1, "'puedo venderte equipo de buena calidad",
               1, ":estira sus cansados brazos",
               2, ":se limpia el sudor de la frente.",
        }));
	
	add_property("nosteal",1);
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
	
	
void event_enter(object ob, string message) {
	if(ob->query_race()=="duergar")
{
	tell_object(ob,"Bienvenido a mi forja, "+ob->query_cap_name()+"().\n",TO);
} else
{
	tell_object(ob,"No eres bienvenido aqui, fuera!.\n",TO);
	attack_by(ob);
	::event_enter(ob,message);
}
}