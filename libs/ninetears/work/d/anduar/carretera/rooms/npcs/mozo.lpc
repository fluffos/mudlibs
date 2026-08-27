inherit "/obj/monster";

void setup() {
      set_name("mozo");
      set_race_ob("/std/races/human");
      add_alias("human");
      add_alias("cuadra");
      set_main_plural("mozos");
      add_plural("mozos");
      add_plural("humanos");
      set_al(-50);
      set_random_stats(10, 17);
      set_cha(8+random(10));
      set_level(10+random(5));
      set_wimpy(15);
      adjust_money(random(10),"silver");
      set_short("mozo de cuadra");
      set_long("Es un joven que se dedica a limpiar el patio, las "
      "caballerizas y los pasillos de la posada.\n");
      load_chat(10, ({ 1, "'Todo el dia igual que aburrimiento.", 
                       1, "'Tengo que encontrar otro trabajo.",
                       1, "'Vos venis de muy lejos buen senyor?."}));
    add_clone("/baseobs/armours/cape",1);
} /* setup() */
