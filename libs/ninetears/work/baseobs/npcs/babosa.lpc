//Kryger 2003//
inherit "/obj/monster";

void setup() {
  set_name("babosa");
      set_short("Babosa");
      set_long(query_short()+"\n"+"Es una pequenya babosa que se arrastra por "
	  "las paredes, comiendo hongos y liquenes.\n");
      add_alias("babosa");
      set_main_plural("babosas");
      add_plural("babosas");
      set_gender(2);
      set_level(1+random(2));
      set_max_hp(query_level() * 8);
  load_chat(10,
  ({
    1, ":se arrastra.",
  }));
}