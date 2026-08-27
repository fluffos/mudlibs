// Guardian - Vilat 22.11.2002

inherit "/obj/guardian";

void setup() {
   	set_name("picoleto");
   	set_short("Picoleto");
	add_alias("civil");
   	set_gender(1);
   	set_main_plural("Picoletos");
   	add_plural("picoletos");
	add_plural("civiles");
   	set_level(5+random(6));
   	set_random_stats(12,17);
   	set_cha(12+random(5));
   	set_race("goblin");
   	set_long("Es un bandido de los muchos que se pueden encontrar en esta "
            "zona. Se gana la vida asaltando a las personas y robandole "
            "todas sus pertenencias. Son peligrosos, sobre todo en las "
            "emboscadas.\n");
   	load_chat(20,
   		({
      		1, "'Dadme vuestro dinero o tendre que quitaros la vida",
      		1, ":mira el tamanyo de tu bolsillo.",
   		}));
   	adjust_money(random(30), "silver");
	set_ciudadania("Inframundo");
	add_move_zone("anduar");
	}
