// Kivara 26.10.2002

inherit "/obj/monster";

void setup() {
	set_name("mustafa");
  set_short("Mustafa");
  set_long(query_short()+"es un viejo tendero con la cara llena de arrugas "
     	"y unos ojos pequenyos y brillantes que estan atentos a todo lo que tocas. "
     	"Parece que va ser dificil ganar algo de dinero a su costa.\n\n");
	set_main_plural("Mustafas");
	add_alias("tendero");	
	add_plural("tenderos");	
	set_gender(1);
	set_level(50+random(5)); //mega dopez xD
	set_random_stats(19, 20);
  set_race("humano");
	set_wimpy(0);
  set_max_hp(query_level() * 50);
  set_hp(query_max_hp());
  set_max_gp(query_level() * 60);
  set_gp(query_max_gp());
	set_max_ep(query_level() * 20);
  set_gp(query_max_ep());	
  load_chat(50,({
 								1, "'Si rompes eso, tendras que pagarlo.",
               	2, "'Barato, barato, oiga!!.",            
               	2, ":te ensenya su mejor genero.",
          	}));
      	load_a_chat(60,({
               	1, "'no volvere a venderte nada!",
               	1, ":guarda sus mejores mercancias en lugar seguro.",
               	1, "'Guardias, a mi!!",
               	}));
	add_clone("/baseobs/long_sword",2);
	add_clone("/baseobs/armours/leather",1);
	init_equip();
	adjust_money(20,"oro");
}

void event_enter(object ob, string message) {
	if (ob->query_race()=="orco"){
		tell_object(ob,"A Mustafa no le gusta tu visita, se enfurece y te ataca!!!\n");		
		 ob->attack_by(TO);
	}else{
		tell_object(ob,"Mustafa te hace una reverencia y te invita a examinar sus preciosos articulos\n");
	}
}