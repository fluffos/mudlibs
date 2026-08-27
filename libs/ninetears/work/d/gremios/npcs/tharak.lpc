// Gareth 7.12.02

inherit "obj/entskill";
#include "/d/gremios/path.h"

void setup()
{	set_name("tharak");
  	set_short("Tharak");
  	set_long("Un duergar bajo, de unos 110 centimetros de altura. Es el encargado de "
  		 "entrenar a los miembros mas jovenes del gremio. Es descendiente del "
  		 "mismisimo Gharz, fundador del gremio Khurgar. Pese a su pequenya"
  		 " altura, Tharak es muy fuerte, y te inspira tal respeto que no te "
  		 "atreverias a atacarle.\n");
  		
	add_alias("guildmaster");
  	set_random_stats(17,29);
  	set_level(66);
  	set_race("duergar");
  	set_gender(1);
  	set_max_hp(query_level() * 70);
      	set_hp(query_max_hp());
      	set_max_gp(query_level() * 60);
      	set_gp(query_max_gp());
	set_max_ep(query_level() * 40);
      	set_gp(query_max_ep());
  	  	
  	add_property("NO_BUDGE",1);
  	add_property("nosteal",1);
  	
  	load_chat(15,
({		2, "'si necesitas mas informacion, lee el cartel.",
		1, "'puedo ayudarte a mejorar en el combate si me lo pides",
}));
	add_property("nosteal", 1);
	add_clone("/baseobs/armas/hacha_de_batalla",1);
	add_clone("/baseobs/armaduras/cota_reforzada",1);
	add_clone("/baseobs/armaduras/yelmo_grande",1);  
	init_equip();
	set_habilidad("furia",100);
	set_habilidad("cabezazo",100);
	add_skill_entrenable("furia",0,100,"general");
	add_skill_entrenable("cabezazo",0,100,"general");
	add_skill_entrenable("decapitar",0,100,"general");
	add_skill_entrenable("reparar",0,100,"general");
	add_skill_entrenable("juzgar",0,100,"general");
	set_coste(random(5)+1);
}


void init() {
	::init();
	add_attack_command(15, "furia", "/comandos/khurgar/furia","furia",0);
	add_attack_command(20, "cabezazo", "/comandos/khurgar/cabezazo","cabezazo",0);
	}


void event_enter(object ob, string message, object *obs) {
	if(ob->query_race()=="duergar")
{
	TO->do_command("'Bienvenido al gremio, "+ob->query_cap_name()+".\n",TO);
}
	else if(living(ob))
{
	tell_object(ob,"No puedes pasar aqui, sal o me vere obligado a matarte!!.\n", TO);
	attack_by(ob);
}
	::event_enter(ob,message,obs);
} 