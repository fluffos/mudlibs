inherit "/obj/monster";

void setup() {
      set_name("camarera");
      set_race_ob("/std/races/human");
      add_alias("human");
    set_gender(2);
      set_main_plural("camareras");
      add_plural("camareras");
      add_plural("humanas");
      set_al(-750);
      set_random_stats(10, 17);
      set_cha(8+random(10));
      set_level(10+random(5));
      set_wimpy(15);
      adjust_money(random(10),"silver");
      set_short("camarera");
      set_long("Es una joven que se dedica a servir a los viajeros, es "
      "hermosa a mas no poder y su voz se parece a la miel.\n");
load_chat(10, ({ 1, "'Si espera un momento enseguida le atiendo."}));
      new("/baseobs/armours/cape")->move(this_object());
      command("equip");
} /* setup() */
