//Kryger 2003//
inherit "/obj/monster";

void setup() {
  set_name("rata");
      set_short("Rata");
      set_long(query_short()+"\n"+"Es la rata mas grande que has visto en tu vida, "
	  "pero supones que para sobrevivir en un lugar asi tienes que ser muy "
	  "fuerte y muy grande.\n");
      add_alias("rata");
      set_main_plural("ratas");
      add_plural("ratas");
      set_gender(1);
      set_level(5+random(2));
      set_max_hp(query_level() * 8);
  load_chat(10,
  ({
    1, ":corretea de un lado a otro.",
	1, ":te mira fijamente.",
  }));
}