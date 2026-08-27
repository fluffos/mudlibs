inherit "/obj/monster";

void setup() {
      set_name("nomada");
      set_race_ob("/std/races/human");
      add_alias("human");
      set_main_plural("nomadas");
      add_plural("nomadas");
      add_plural("humans");
      set_al(-10);
      set_random_stats(10, 17);
      set_cha(6+random(10));
      set_level(5+random(5));
      set_wimpy(10);
   add_move_zone("anduar");
      adjust_money(random(100),"silver");
      set_short("nomada");
      set_long("Es un nomada de algun remoto desierto que parece haber venido "
      "a comprar o intercambiar bienes.\n");
      load_chat(50, ({ 1, "'Demonios de ciudad hace mucho frio.", 
                       1, "'Anyoro mi hogar.",
                       1, "'Que Paris este con vos buen senyor.",
                       1, "'Vos venis de muy lejos buen senyor?."}));
      add_clone("/baseobs/armours/cape",1);
      ::init_equip();
} /* setup() */
