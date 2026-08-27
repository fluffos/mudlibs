inherit "/obj/monster";

void setup() {
  set_name("aranya");
      set_short("Aranya");
      set_long(query_short()+"\n"+"Es una pequenya aranya, aunque su cuerpo "
	  "negro y rojo no te inspira mucha confianza.\n");
      set_main_plural("aranyas");
      add_plural("aranyas");
      set_gender(2);
      set_level(5+random(3));
      set_max_hp(query_level() * 8);
  load_chat(10,
  ({
    1, ":teje una tela.",
	1, ":te mira fijamente.",
  }));
}