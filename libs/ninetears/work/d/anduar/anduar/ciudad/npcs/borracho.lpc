inherit "/obj/monster";
void setup() {
      set_name("borracho");
      set_race_ob("/std/races/human");
      add_alias("human");
      set_main_plural("borracho");
      add_plural("humans");
      set_al(-100);
      set_random_stats(5, 12);
      set_cha(6+random(8));
      set_level(1+random(2));
      set_wimpy(10);
      adjust_money(random(10),"copper");
      set_short("borracho");
      set_long("Es un borracho que vive en esta chabola en el arbol, "
      "por su aspecto no ha comido en dias y no se ha banyado en anyos.\n");
load_chat(15, 
({ 1, "'Si me invita a una cerveza le cuento una historia",
      }));
      add_clone("/baseobs/armours/cape",1);
::init_equip();
} /* setup() */
