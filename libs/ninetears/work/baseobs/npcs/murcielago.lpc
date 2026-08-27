//Kryger 2003//
inherit "/obj/monster";

void setup() {
  set_name("murcielago");
      set_short("Murcielago");
      set_long(query_short()+"\n"+"Es una rata-voladora, mas conocida como "
	  "murcielago.\n");
      add_alias("murcielago");
      set_main_plural("murcielagos");
      add_plural("murcielagos");
      set_gender(1);
      ataque1="clava sus colmillos en tu cuello";
      ataque2="aranya una mano";
      ataque3="muerde la pierna";
      set_level(4+random(2));
      set_max_hp(query_level() * 8);
  load_chat(10,
  ({
    1, ":vuela por encima de ti.",
  }));
}