//Kryger 2003//
inherit "/obj/monster";

void setup() {
  set_name("vibora");
      set_short("Vibora");
      set_long(query_short()+"\n"+"Ves una vibora de un metro de longitud, que "
	  "sisea amenazadoramente levantando su cabeza"
	"y sacando la lengua, en busca de una futura presa.\n");
      set_main_plural("viboras");
      add_alias("viboras");
	add_alias("vibora");
	add_plural("viboras");
      set_gender(1);
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      set_aggressive(1);
  load_chat(10,
  ({
    1, ":se arrastra.",
	1, "'zZzZzZz.",
  }));
}